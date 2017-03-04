#include <stdexcept>
#include <array>
#include <string>
#include <thread>
#include <chrono>

#include "NetworkManager.hpp"
#include "Logger.hpp"

using boost::asio::ip::tcp;

fxtm::NetworkManager::NetworkManager(const std::string & address, const std::string & port)
    : mSocket(mService)
{
    tcp::resolver resolver(mService);
    boost::asio::connect(mSocket, resolver.resolve({address.c_str(), port.c_str()}));
}

void fxtm::NetworkManager::sendAndReceive(const std::string & data)
{
    Logger::log("CLIENT | Sending: " + data);

    auto resp = sendAndReceiveImpl(data);

    Logger::log("CLIENT | Response: " + resp);

    std::this_thread::sleep_for(std::chrono::seconds(1));
}

std::string fxtm::NetworkManager::sendAndReceiveImpl(const std::string &data)
{
    size_t sendBytes = boost::asio::write(mSocket, boost::asio::buffer(data.data(), data.size()));

    if (sendBytes != data.size())
        throw std::runtime_error("Can't send data to server.");

    std::array<char, fxtm::defaultMessageSize> response;
    size_t recieveBytes = boost::asio::read(mSocket, boost::asio::buffer(&response, fxtm::defaultMessageSize));

    return std::string(response.cbegin(), response.cbegin() + recieveBytes);
}
