#include <thread>
#include "clientimpl.hpp"

fxtm::ClientImpl::ClientImpl(const std::string & address, const std::string & port)
    : mRunning(true)
    , mNetworkManager(address, port)
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
