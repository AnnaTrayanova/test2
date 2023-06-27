#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <iostream>
#include "product.h"

class Order {
private:
    static int nextId;
    int id;
    std::vector<std::pair<const Product*, int>> items;

public:
    Order();
    ~Order();
    void addItem(const Product* product, int quantity);
    void clear();
    void clone(const Order& other);
    void print(std::ostream& os) const;
};

#endif  // ORDER_H

