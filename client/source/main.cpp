#include <iostream>

#include "client.hpp"

int main()
{
    fxtm::Client client;

    std::cout << "Press any key to stop client" << std::endl;

	client.start();

	//sleep main thread until key pressed
    std::cin.get();

    client.stop();

    return 0;
}

