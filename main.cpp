#include <iostream>
#include "manager.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: program_name catalog_file" << std::endl;
        return 1;
    }

    try {
        OrderManager orderManager(argv[1]);

        std::string command;
        while (std::getline(std::cin, command)) {
            orderManager.processCommand(command);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

