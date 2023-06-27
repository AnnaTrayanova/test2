#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include "catalog.h"
#include "order.h"

class OrderManager {
private:
    Catalog catalog;
    Order* currentOrder;
    Order* previousOrder;

public:
    OrderManager(const std::string& catalogFile);
    ~OrderManager();
    void processCommand(const std::string& command);
};

#endif  // ORDER_MANAGER_H

