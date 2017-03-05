#include <iostream>

#include <boost/lexical_cast.hpp>

#include "Server.hpp"
#include "Logger.hpp"

int main(int argc, char ** argv)
{
    try
    {
        short port = 2001;
        size_t syncInterval = 30;

        if (argc > 1)
            port = boost::lexical_cast<short>(argv[1]);
        if (argc > 2)
            syncInterval = boost::lexical_cast<size_t>(argv[2]);

        fxtm::Server server(port, syncInterval);
        server.run();
    }
    catch (const std::exception & ex)
    {
        fxtm::Logger::log(ex.what());
    }

    return 0;
}
