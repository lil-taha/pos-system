// MODULE 1b - Supplier & Purchase Order (Team Lead)
// TODO (Team Lead): implement in src/Supplier.cpp
#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>

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
    void markDelivered();
    bool isDelivered() const;
    void display() const;
};

#endif
