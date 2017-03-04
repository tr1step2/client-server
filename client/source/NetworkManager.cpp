#include <stdexcept>
#include <iostream>
#include <thread>

#include "TransferManager.hpp"

fxtm::TransferManager::TransferManager()
{

}

void fxtm::TransferManager::sendAndReceive(const std::string & data)
{
    std::cout << "Send : " << data << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds((rand() % 3) + 1));
    std::cout << "Receive : nothing" << std::endl;
}
