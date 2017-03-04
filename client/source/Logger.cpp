#include <iostream>

#include "Logger.hpp"

void fxtm::Logger::log(std::string && message)
{
	std::cout << message << std::endl;
}
