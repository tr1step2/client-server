#include <thread>
#include "clientimpl.hpp"

fxtm::ClientImpl::ClientImpl(const std::string & host, const short port)
    : mRunning(true)
    , mNetworkManager(host, port)
{
}

void fxtm::ClientImpl::start()
{
    while (mRunning)
    {
        mNetworkManager.sendAndReceive(mDataManager.getData());
    }
}

void fxtm::ClientImpl::stop()
{
    mRunning.store(false);
}
