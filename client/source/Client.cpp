#include <iostream>
#include <thread>

#include "client.hpp"

fxtm::Client::Client()
    : mImpl(new fxtm::ClientImpl)
{
}

void fxtm::Client::start()
{
    mClientThread.reset(new std::thread([this]()
    {
        try
        {
            mImpl->start();
        }
        catch(const std::exception & ex)
        {
            std::cout << "Some exception occured: " << ex.what() << std::endl;
        }
    }));
}

void fxtm::Client::stop()
{
    mImpl->stop();
	mClientThread->join();
}
