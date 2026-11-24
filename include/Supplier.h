// MODULE 1b - Supplier & Purchase Order (Team Lead)
#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include <vector>
#include "Inventory.h"

class Supplier {
private:
    int id;
    std::string name;
    std::string contact;

public:
    Supplier(int id, const std::string& name, const std::string& contact);
    std::string getName() const;
    void display() const;
};

class PurchaseOrder {
private:
    int poNumber;
    std::string sku;
    int quantity;
    bool delivered;

public:
    PurchaseOrder(int poNumber, const std::string& sku, int quantity);
    int getPoNumber() const;
    std::string getSku() const;
    int getQuantity() const;
    void markDelivered();
    bool isDelivered() const;
    void display() const;
};

// Creates Purchase Orders automatically when stock drops below the threshold
class PurchaseOrderManager {
private:
    std::vector<PurchaseOrder> orders;
    int nextPoNumber;

public:
    explicit PurchaseOrderManager(int firstPoNumber = 881);

    // Returns the new PO number, or 0 if the product is not below its threshold
    int checkAndGenerate(const PhysicalProduct& product);

    // Marks the PO delivered and adds the ordered quantity back to the warehouse stock
    bool receiveDelivery(int poNumber, Warehouse& warehouse);

    void displayAll() const;
};

#endif
