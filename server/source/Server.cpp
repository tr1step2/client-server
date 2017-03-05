#include "Server.hpp"
#include "Session.hpp"

using boost::asio::ip::tcp;

fxtm::Server::Server(const short port)
    : mAcceptor(mService, tcp::endpoint(tcp::v4(), port))
    , mSocket(mService)
    , mDataManager(new fxtm::DataManager)
{
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

