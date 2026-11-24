// Team Lead's demo for Milestone 1
#include <iostream>
#include "Inventory.h"

int main() {
    Warehouse north("WAREHOUSE_NORTH");
    north.addProduct(PhysicalProduct("SKU-4992", "Wireless Mouse", 25.00, 6, 5, "B-101", "2028-01-01"));

    DigitalProduct ebook("SKU-7001", "C++ eBook", 10.00, "LIC-XYZ");
    ebook.display();

    north.displayAll();

    PhysicalProduct* mouse = north.findBySku("SKU-4992");
    if (mouse && mouse->reduceStock(2))
        std::cout << "Sold 2. Stock now " << mouse->getStock() << "\n";
    if (mouse && mouse->isBelowThreshold())
        std::cout << "Below reorder threshold -> a Purchase Order should be generated\n";

    std::cout << (mouse->reduceStock(999) ? "BUG" : "Negative stock blocked") << "\n";
    return 0;
}
