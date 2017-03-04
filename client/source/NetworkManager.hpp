#pragma once

#include <string>

namespace fxtm
{

class NetworkManager
{
public:
    NetworkManager();

    void sendAndReceive(const std::string & data);
};

} // ns fxtm
