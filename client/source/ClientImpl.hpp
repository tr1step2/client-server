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
    ClientImpl(const std::string & host, const short port);

    void start();
    void stop();

private:
    NetworkManager mNetworkManager;
    DataManager mDataManager;
    Logger mLogger;

    std::atomic<bool> mRunning;
};

} // ns fxtm
