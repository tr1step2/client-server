#include <iostream>

#include "Server.hpp"

int main(int argc, char ** argv)
{
    try
    {
        //listen 2001 port, store data on disk every 30 sec
        fxtm::Server server(2001, 30);
        server.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
