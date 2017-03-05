#include <boost/lexical_cast.hpp>

#include "Session.hpp"
#include "Logger.hpp"

using boost::asio::ip::tcp;

fxtm::Session::Session(tcp::socket socket, std::shared_ptr<DataManager> dataManager)
    : mSocket(std::move(socket))
    , mDataManager(dataManager)
{
}

void fxtm::Session::start()
{
    doRead();
}

void fxtm::Session::doRead()
{
    auto self = shared_from_this();
    boost::asio::async_read(mSocket, boost::asio::buffer(mData, fxtm::defaultMessageSize),
        [this, self](boost::system::error_code ec, std::size_t length)
        {
            Logger::log("SERVER | Receive: " + std::string((char*)&mData));

            std::uint16_t value = boost::lexical_cast<std::uint16_t>((char*)&mData);

            double avg = 0;
            mDataManager->updateData(value, avg);

            storeDoubleInData(avg);

            doWrite();
        });
}

void fxtm::Session::doWrite()
{
    auto self = shared_from_this();
    boost::asio::async_write(mSocket, boost::asio::buffer(mData, fxtm::defaultMessageSize),
        [this, self](boost::system::error_code ec, size_t length)
        {
            Logger::log("SERVER | Send: " + std::string(mData.cbegin(), mData.cend()));

            doRead();
    });
}

void fxtm::Session::storeDoubleInData(double value)
{
    memset(&mData, 0, fxtm::defaultMessageSize);
    std::string ss = boost::lexical_cast<std::string>(value);
    memcpy(&mData, ss.c_str(), ss.size());
}

