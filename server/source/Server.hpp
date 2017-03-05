#pragma once

#include <string>
#include <memory>
#include <thread>

#include "boost/asio.hpp"

#include "DataManager.hpp"

namespace fxtm
{

class Server
{
public:
    Server(const short port = 2001);

    void run();

private:
    void doAccept();

private:
    boost::asio::io_service mService;
    boost::asio::ip::tcp::acceptor mAcceptor;
    boost::asio::ip::tcp::socket mSocket;

    std::shared_ptr<DataManager> mDataManager;
};

} // ns fxtm
