#pragma once

#include <string>
#include <memory>
#include <thread>
#include <array>

#include "boost/asio.hpp"

#include "DataManager.hpp"
#include "Constants.hpp"

namespace fxtm
{

class Session : public std::enable_shared_from_this<Session>
{
public:
    Session(boost::asio::ip::tcp::socket socket,
            std::shared_ptr<DataManager> dataManager);

    void start();
private:
    void doRead();
    void doWrite();

    void storeDoubleInData(double value);
private:
    boost::asio::ip::tcp::socket mSocket;
    std::array<char, defaultMessageSize> mData;

    std::shared_ptr<DataManager> mDataManager;
};

} // ns fxtm
