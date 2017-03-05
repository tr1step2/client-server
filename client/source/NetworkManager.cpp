#include <stdexcept>
#include <array>
#include <string>
#include <thread>
#include <chrono>

#include "NetworkManager.hpp"
#include "Logger.hpp"

using boost::asio::ip::tcp;

fxtm::NetworkManager::NetworkManager(const std::string & address,
                                     const std::string & port)
    : mAddress(address)
    , mPort(port)
    , mResolver(mService)
{
}

void fxtm::NetworkManager::sendAndReceive(const std::string & data)
{
    Logger::log("CLIENT | Sending: " + data);

    auto resp = sendAndReceiveImpl(data);

    Logger::log("CLIENT | Response: " + resp);

    std::this_thread::sleep_for(std::chrono::seconds(2));
}

std::string fxtm::NetworkManager::sendAndReceiveImpl(const std::string &data)
{
    tcp::socket socket(mService);
    boost::asio::connect(socket, mResolver.resolve({mAddress.c_str(), mPort.c_str()}));

    size_t sendBytes = socket.write_some(boost::asio::buffer(data.data(), data.size()));

    if (sendBytes != data.size())
        throw std::runtime_error("Can't send data to server.");

    std::array<char, fxtm::defaultMessageSize> buf;
    size_t readBytes = boost::asio::read(socket, boost::asio::buffer(buf, fxtm::defaultMessageSize));

    return std::string(buf.cbegin(), buf.cbegin() + readBytes);
}
