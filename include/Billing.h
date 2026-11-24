// MODULE 2b - Billing & Checkout Engine (Ali)
// TODO (Ali): implement in src/Billing.cpp
#ifndef BILLING_H
#define BILLING_H

#include <string>
#include <vector>
#include "Discount.h"

class TaxCalculator {
    double taxRate;   // e.g. 0.08
public:
    explicit TaxCalculator(double taxRate);
    double calculateTax(double amount) const;
};

class CartItem {
    std::string sku;
    std::string name;
    double unitPrice;
    int quantity;
public:
    CartItem(const std::string& sku, const std::string& name, double unitPrice, int quantity);
    double lineTotal() const;
    std::string getSku() const;
    int getQuantity() const;
};

class Invoice {
    std::vector<CartItem> items;
    double subtotal, tax, total;
public:
    Invoice();
    void addItem(const CartItem& item);
    void computeTotal(const DiscountStrategy& discount, const TaxCalculator& taxCalc);
    double getTotal() const;                          // Usman's Payment module uses this
    const std::vector<CartItem>& getItems() const;    // Usman's Analytics uses this
    void print() const;
};

#endif
