#include "Inventory.h"
#include <iostream>

// ---------- PhysicalProduct ----------
PhysicalProduct::PhysicalProduct(const std::string& sku, const std::string& name, double price,
                                 int stock, int reorderThreshold,
                                 const std::string& batchNo, const std::string& expiryDate)
    : Item(sku, name, price), stock(stock), reorderThreshold(reorderThreshold),
      batchNo(batchNo), expiryDate(expiryDate) {}

int PhysicalProduct::getStock() const { return stock; }
int PhysicalProduct::getReorderThreshold() const { return reorderThreshold; }

bool PhysicalProduct::reduceStock(int qty) {
    if (qty <= 0 || qty > stock) return false;   // encapsulation: never negative
    stock -= qty;
    return true;
}

void PhysicalProduct::addStock(int qty) {
    if (qty > 0) stock += qty;
}

bool PhysicalProduct::isBelowThreshold() const { return stock < reorderThreshold; }

std::string PhysicalProduct::getType() const { return "Physical"; }

void PhysicalProduct::display() const {
    std::cout << sku << " | " << name << " | $" << price
              << " | stock: " << stock << " (reorder below " << reorderThreshold << ")\n";
}

// ---------- DigitalProduct ----------
DigitalProduct::DigitalProduct(const std::string& sku, const std::string& name, double price,
                               const std::string& licenseKey)
    : Item(sku, name, price), licenseKey(licenseKey) {}

std::string DigitalProduct::getType() const { return "Digital"; }

void DigitalProduct::display() const {
    std::cout << sku << " | " << name << " | $" << price << " | digital license\n";
}

// ---------- Warehouse ----------
Warehouse::Warehouse(const std::string& branchName) : branchName(branchName) {}

void Warehouse::addProduct(const PhysicalProduct& p) { products.push_back(p); }

PhysicalProduct* Warehouse::findBySku(const std::string& sku) {
    for (auto& p : products)
        if (p.getSku() == sku) return &p;
    return nullptr;
}

void Warehouse::displayAll() const {
    std::cout << "--- " << branchName << " ---\n";
    for (const auto& p : products) p.display();
}

std::string Warehouse::getBranchName() const { return branchName; }
