#include <iostream>

#include "Server.hpp"

int main(int argc, char ** argv)
{
    try
    {
        fxtm::Server server(2001);
        server.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
