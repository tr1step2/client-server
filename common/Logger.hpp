#pragma once

#include <string>

#include <boost/date_time.hpp>

using namespace boost::posix_time;


namespace fxtm
{

class Logger
{
public:
    static void log(std::string && message)
    {
        ptime now = microsec_clock::local_time();
        std::cout << now << " | " << message << std::endl;
    }
};

} // ns fxtm
