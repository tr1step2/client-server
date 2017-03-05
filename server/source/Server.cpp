#include "Server.hpp"
#include "Session.hpp"
#include "Logger.hpp"

using boost::asio::ip::tcp;

fxtm::Server::Server(const short port, size_t syncInterval)
    : mAcceptor(mService, tcp::endpoint(tcp::v4(), port))
    , mSocket(mService)
    , mDataManager(new fxtm::DataManager(syncInterval))
{
    Logger::log("SERVER | Listening port: " + std::to_string(port));
    doAccept();
}

void fxtm::Server::doAccept()
{
    mAcceptor.async_accept(mSocket, [this](boost::system::error_code ec)
    {
        //create connection
        if (!ec)
        {
            std::make_shared<fxtm::Session>(std::move(mSocket), mDataManager)->start();
        }

        //wait for another connections
        doAccept();
    });
}

void fxtm::Server::run()
{
    mService.run();
}

