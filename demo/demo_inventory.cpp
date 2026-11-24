// Team Lead's demo for Milestone 1
#include <iostream>
#include "Inventory.h"
#include "Supplier.h"

int main() {
    // Inventory
    Warehouse north("WAREHOUSE_NORTH");
    north.addProduct(PhysicalProduct("SKU-4992", "Wireless Mouse", 25.00, 6, 5, "B-101", "2028-01-01"));
    DigitalProduct ebook("SKU-7001", "C++ eBook", 10.00, "LIC-XYZ");
    ebook.display();
    north.displayAll();

    PhysicalProduct* mouse = north.findBySku("SKU-4992");
    if (mouse && mouse->reduceStock(2))
        std::cout << "Sold 2. Stock now " << mouse->getStock() << "\n";
    std::cout << (mouse->reduceStock(999) ? "BUG" : "Negative stock blocked") << "\n";

    // Supplier and Purchase Orders
    Supplier acme(1, "Acme Traders", "acme@example.com");
    acme.display();

    PurchaseOrderManager manager;
    int po = manager.checkAndGenerate(*mouse);
    if (po != 0) std::cout << "Auto-Trigger: stock below threshold -> PO #" << po << " generated\n";
    manager.displayAll();

    manager.receiveDelivery(po, north);
    std::cout << "After delivery, stock is " << mouse->getStock() << "\n";
    manager.displayAll();
    return 0;
}
