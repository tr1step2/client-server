#pragma once

#include <memory>
#include <thread>

#include "ClientImpl.hpp"

namespace fxtm
{

class Client
{
public:
    Client(const std::string & host,
           const short port);

    void start();
    void stop();

private:
    std::shared_ptr<ClientImpl> mImpl;
    std::unique_ptr<std::thread> mClientThread;
};

} // ns fxtm
