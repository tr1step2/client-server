#include <sstream>

#include "DataManager.hpp"

std::string fxtm::DataManager::getData()
{
    std::stringstream ss;
    ss << (std::rand() % 1024);

    return ss.str();
}
