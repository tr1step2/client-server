#pragma once

#include <atomic>

#include "NetworkManager.hpp"
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
    NetworkManager mNetworkManager;
    DataManager mDataManager;
    Logger mLogger;

    std::atomic<bool> mRunning;
};

} // ns fxtm
