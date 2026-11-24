// Ali's demo for Milestone 1
#include <iostream>
#include <iomanip>
#include "Billing.h"

int main() {
    std::cout << std::fixed << std::setprecision(2);

    // Scan an item and build an invoice
    CartItem mouse("SKU-4992", "Wireless Mouse", 25.00, 2);
    std::cout << "Scanned " << mouse.getSku() << " (" << mouse.getName() << " x"
              << mouse.getQuantity() << ") @ $" << mouse.getUnitPrice()
              << " = $" << mouse.lineTotal() << "\n";

    Invoice invoice;
    invoice.addItem(mouse);

    PercentageDiscount promo(15);
    TaxCalculator tax(0.08);
    std::cout << "Applying PercentageDiscount 15%\n";
    invoice.computeTotal(promo, tax);
    invoice.print();

    // Polymorphism: one base-class pointer type, three different behaviours
    FlatDiscount flat(10);
    PercentageDiscount pct(15);
    BuyOneGetOne bogo;
    const DiscountStrategy* strategies[] = {&flat, &pct, &bogo};
    const char* names[] = {"FlatDiscount $10", "PercentageDiscount 15%", "BuyOneGetOne"};

    std::cout << "\nPolymorphism check on $100.00:\n";
    for (int i = 0; i < 3; i++)
        std::cout << names[i] << " -> $" << strategies[i]->applyDiscount(100.00) << "\n";

    return 0;
}
