#include <fstream>
#include <stdexcept>
#include "catalog.h"

Catalog::Catalog(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open catalog file");
    }

    int id;
    std::string name;
    double price;

    while (file >> id >> name >> price) {
        products.push_back(new Product(id, name, price));
    }
}

Catalog::~Catalog() {
    for (Product* product : products) {
        delete product;
    }
}

const Product* Catalog::findProductById(int id) const {
    for (const Product* product : products) {
        if (product->getId() == id) {
            return product;
        }
    }
    return nullptr;
}
