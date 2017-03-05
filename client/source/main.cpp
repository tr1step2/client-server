#include <iostream>
#include <string>

#include "Client.hpp"
#include "Logger.hpp"

int main(int argc, char ** argv)
{
	try
	{
        std::string host = "127.0.0.1";
        short port = 2001;

        if (argc > 1)
            host = boost::lexical_cast<std::string>(argv[1]);
        if (argc > 2)
            port = boost::lexical_cast<short>(argv[2]);

        fxtm::Client client(host, port);

        std::cout << "Press any key to stop client" << std::endl;

        client.start();

		//sleep main thread until key pressed
        std::cin.get();

        client.stop();
    }
    catch (const std::exception & ex)
    {
        fxtm::Logger::log(ex.what());
    }

    return 0;
}
