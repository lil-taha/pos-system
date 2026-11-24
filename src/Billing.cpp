#include "Billing.h"
#include <iostream>
#include <iomanip>

// ---------- TaxCalculator ----------
TaxCalculator::TaxCalculator(double taxRate) : taxRate(taxRate) {}

double TaxCalculator::calculateTax(double amount) const {
    return amount * taxRate;
}

// ---------- CartItem ----------
CartItem::CartItem(const std::string& sku, const std::string& name, double unitPrice, int quantity)
    : sku(sku), name(name), unitPrice(unitPrice), quantity(quantity) {}

double CartItem::lineTotal() const { return unitPrice * quantity; }
std::string CartItem::getSku() const { return sku; }
std::string CartItem::getName() const { return name; }
double CartItem::getUnitPrice() const { return unitPrice; }
int CartItem::getQuantity() const { return quantity; }

// ---------- Invoice ----------
Invoice::Invoice() : subtotal(0), tax(0), total(0) {}

void Invoice::addItem(const CartItem& item) { items.push_back(item); }

void Invoice::computeTotal(const DiscountStrategy& discount, const TaxCalculator& taxCalc) {
    double gross = 0;
    for (const auto& item : items) gross += item.lineTotal();

    subtotal = discount.applyDiscount(gross);   // polymorphic call
    tax = taxCalc.calculateTax(subtotal);
    total = subtotal + tax;
}

double Invoice::getSubtotal() const { return subtotal; }
double Invoice::getTax() const { return tax; }
double Invoice::getTotal() const { return total; }
const std::vector<CartItem>& Invoice::getItems() const { return items; }

void Invoice::print() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "----- INVOICE -----\n";
    for (const auto& item : items) {
        std::cout << item.getSku() << " (" << item.getName() << " x" << item.getQuantity()
                  << ") @ $" << item.getUnitPrice() << " = $" << item.lineTotal() << "\n";
    }
    std::cout << "Subtotal: $" << subtotal << " | Tax: $" << tax
              << " | Final Total: $" << total << "\n";
}
