#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include "product.h"

class Catalog {
private:
    std::vector<Product*> products;

public:
    Catalog(const std::string& filename);
    ~Catalog();
    const Product* findProductById(int id) const;
};

#endif  // CATALOG_H
