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
        mImpl->start();
    }));
}

void fxtm::Client::stop()
{
    mImpl->stop();
	mClientThread->join();
}
