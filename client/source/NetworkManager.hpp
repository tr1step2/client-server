#pragma once

#include <string>
#include <boost/asio.hpp>

namespace fxtm
{

constexpr size_t defaultMessageSize = 32;

class NetworkManager
{
public:
    NetworkManager(const std::string & address = "127.0.0.1", const std::string & port = "2001");
    void sendAndReceive(const std::string & data);

private:
    std::string sendAndReceiveImpl(const std::string & data);

private:
    boost::asio::io_service mService;
    boost::asio::ip::tcp::socket mSocket;
};

} // ns fxtm
