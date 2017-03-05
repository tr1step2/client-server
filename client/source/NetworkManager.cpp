#include <stdexcept>
#include <array>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>

#include "NetworkManager.hpp"
#include "Logger.hpp"

using boost::asio::ip::tcp;

fxtm::NetworkManager::NetworkManager(const std::string & address,
                                     const std::string & port)
    : mSocket(mService)
{
	boost::asio::connect(mSocket,
		boost::asio::ip::tcp::resolver(mService).resolve({ address, port }));
}

void fxtm::NetworkManager::sendAndReceive(const std::string & data)
{
    Logger::log("CLIENT | Sending: " + data);

    auto resp = sendAndReceiveImpl(data);

    Logger::log("CLIENT | Response: " + resp);
}

std::string fxtm::NetworkManager::sendAndReceiveImpl(const std::string &data)
{
	std::array<char, fxtm::defaultMessageSize> buf = {};
	std::copy(data.cbegin(), data.cend(), buf.begin());

	//send data
    size_t sendBytes = boost::asio::write(mSocket,
		boost::asio::buffer(buf, fxtm::defaultMessageSize));

    if (sendBytes != fxtm::defaultMessageSize)
        throw std::runtime_error("Can't send data to server.");

	//clear buffer
	memset(&buf, 0, fxtm::defaultMessageSize);

	//read data
    size_t readBytes = boost::asio::read(mSocket, 
		boost::asio::buffer(buf, fxtm::defaultMessageSize));

    return std::string(buf.begin(), buf.begin() + readBytes);
}
