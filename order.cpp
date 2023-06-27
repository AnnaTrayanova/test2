#include "order.h"

int Order::nextId = 1;

Order::Order() : id(nextId++) {}

Order::~Order() {
    clear();
}

void Order::addItem(const Product* product, int quantity) {
    items.push_back(std::make_pair(product, quantity));
}

void Order::clear() {
    items.clear();
}

void Order::clone(const Order& other) {
    clear();
    for (const auto& item : other.items) {
        addItem(item.first, item.second);
    }
}

void Order::print(std::ostream& os) const {
    os << "#" << id << '\n';
    double totalPrice = 0.0;

    for (const auto& item : items) {
        const Product* product = item.first;
        int quantity = item.second;
        double itemPrice = product->getPrice() * quantity;

        os << product->getName() << ' ' << quantity << 'x $' << product->getPrice() << '\n';
        totalPrice += itemPrice;
    }

    os << "--\n";
    os << "$" << totalPrice << " total\n";
}

