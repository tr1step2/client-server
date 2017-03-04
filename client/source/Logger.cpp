#include <iostream>

#include "Logger.hpp"

void fxtm::Logger::log(const std::string & message)
{
    std::cout << message << std::endl;
}
