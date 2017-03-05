#include <sstream>

#include "DataManager.hpp"

std::string fxtm::DataManager::getData()
{
    std::stringstream ss;
    ss << ((std::rand() % 4) + 1);

    return ss.str();
}
