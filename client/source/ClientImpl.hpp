#pragma once

#include <atomic>

#include "TransferManager.hpp"
#include "DataManager.hpp"
#include "Logger.hpp"

namespace fxtm
{

class ClientImpl
{
public:
    ClientImpl();

    void start();
    void stop();

private:
    TransferManager mTransferManager;
    DataManager mDataManager;
    Logger mLogger;

    std::atomic<bool> mRunning;
};

} // ns fxtm
