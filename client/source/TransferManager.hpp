#pragma once

#include <string>

namespace fxtm
{

class TransferManager
{
public:
    TransferManager();

    void sendAndReceive(const std::string & data);
};

} // ns fxtm
