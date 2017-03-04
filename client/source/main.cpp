#include <iostream>

#include "Client.hpp"

int main()
{
	try
	{
		fxtm::Client client;

		std::cout << "Press any key to stop client" << std::endl;

		client.start();

		//sleep main thread until key pressed
		std::cin.get();

		client.stop();
	}
	catch (const std::exception & ex)
	{
		std::cout << "Some exception occured: " << ex.what() << std::endl;
	}

    return 0;
}
