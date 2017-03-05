#pragma once

#include <string>

#include <boost/asio.hpp>

#include "Constants.hpp"

namespace fxtm
{

class NetworkManager
{
public:
    NetworkManager(const std::string & host, const short port);
    void sendAndReceive(const std::string & data);

private:
    std::string sendAndReceiveImpl(const std::string & data);

private:
    boost::asio::io_service mService;
	boost::asio::ip::tcp::socket mSocket;
    
};

} // ns fxtm
