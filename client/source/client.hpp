#pragma once

#include <memory>
#include <thread>
#include "clientimpl.hpp"

namespace fxtm
{

class Client
{
public:
    Client();

    void start();
    void wait();
    void stop();

private:
    std::shared_ptr<ClientImpl> mImpl;
    std::unique_ptr<std::thread> mClientThread;
};

} // ns fxtm
