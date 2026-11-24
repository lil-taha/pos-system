// MODULE 1 - Product & Inventory Registry (Team Lead)
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include "Item.h"

class PhysicalProduct : public Item {
private:
    int stock;
    int reorderThreshold;
    std::string batchNo;
    std::string expiryDate;

public:
    PhysicalProduct(const std::string& sku, const std::string& name, double price,
                    int stock, int reorderThreshold,
                    const std::string& batchNo = "", const std::string& expiryDate = "");

    int getStock() const;
    int getReorderThreshold() const;
    bool reduceStock(int qty);      // returns false if stock would go negative
    void addStock(int qty);
    bool isBelowThreshold() const;

    std::string getType() const override;
    void display() const override;
};

class DigitalProduct : public Item {
private:
    std::string licenseKey;

public:
    DigitalProduct(const std::string& sku, const std::string& name, double price,
                   const std::string& licenseKey);

    std::string getType() const override;
    void display() const override;
};

class Warehouse {
private:
    std::string branchName;
    std::vector<PhysicalProduct> products;

public:
    explicit Warehouse(const std::string& branchName);

    void addProduct(const PhysicalProduct& p);
    PhysicalProduct* findBySku(const std::string& sku);   // nullptr if not found
    void displayAll() const;
    std::string getBranchName() const;
};

#endif
