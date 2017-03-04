#include <thread>
#include "clientimpl.hpp"

fxtm::ClientImpl::ClientImpl()
    : mRunning(true)
{
}

void fxtm::ClientImpl::start()
{
    while (mRunning)
    {
        mTransferManager.sendAndReceive(mDataManager.getData());
    }
}

void fxtm::ClientImpl::stop()
{
    mRunning.store(false);
}
