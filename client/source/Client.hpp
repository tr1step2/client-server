#pragma once

#include <memory>
#include <thread>

#include "ClientImpl.hpp"

namespace fxtm
{

class Client
{
public:
    Client(const std::string & address = "127.0.0.1",
           const std::string & port = "2001");

    void start();
    void wait();
    void stop();

private:
    std::shared_ptr<ClientImpl> mImpl;
    std::unique_ptr<std::thread> mClientThread;
};

} // ns fxtm
