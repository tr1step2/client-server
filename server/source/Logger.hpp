#pragma once

#include <string>

namespace fxtm
{

class Logger
{
public:
    static void log(std::string && message);
};

} // ns fxtm
