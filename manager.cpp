#include <iostream>
#include <sstream>
#include "manager.h"

OrderManager::OrderManager(const std::string& catalogFile) : catalog(catalogFile), currentOrder(nullptr), previousOrder(nullptr) {}

OrderManager::~OrderManager() {
    delete currentOrder;
    delete previousOrder;
}

void OrderManager::processCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string cmd;

    if (!(iss >> cmd)) {
        return;  // Empty command, do nothing
    }

    if (cmd == "add") {
        int productId, quantity;
        if (iss >> productId >> quantity) {
            const Product* product = catalog.findProductById(productId);
            if (product) {
                if (!currentOrder) {
                    currentOrder = new Order();
                }
                currentOrder->addItem(product, quantity);
            } else {
                std::cout << "no such product" << std::endl;
            }
        }
    } else if (cmd == "checkout") {
        if (currentOrder) {
            if (previousOrder) {
                delete previousOrder;
            }
            previousOrder = currentOrder;
            currentOrder = nullptr;
            previousOrder->print(std::cout);
            previousOrder->clear();
        }
    } else if (cmd == "prev") {
        if (previousOrder) {
            previousOrder->print(std::cout);
        }
    } else if (cmd == "clone") {
        if (previousOrder) {
            if (!currentOrder) {
                currentOrder = new Order();
            }
            currentOrder->clone(*previousOrder);
        }
    } else {
        std::cout << "unknown command: " << cmd << std::endl;
    }
}

