// Usman's demo for Milestone 1
#include <iostream>
#include <iomanip>
#include "Payment.h"
#include "Analytics.h"

int main() {
    std::cout << std::fixed << std::setprecision(2);
    double amount = 45.90;

    // Polymorphism: the same pay() call behaves differently for each processor
    CashPayment cash;
    CreditCardGateway card("**** **** **** 4417");
    WalletPayment wallet("WALLET-77");
    PaymentProcessor* processors[] = {&cash, &card, &wallet};

    for (int i = 0; i < 3; i++) {
        std::cout << "Paying $" << amount << " by " << processors[i]->getMethodName() << "\n";
        bool ok = processors[i]->pay(amount);
        std::cout << (ok ? "-> Payment successful\n\n" : "-> Payment failed\n\n");
    }

    // A payment that should be declined
    std::cout << "Trying a very large card payment:\n";
    card.pay(9000.00);

    // Sales analytics
    SalesReport report;
    report.addRecord(SalesRecord("SKU-4992", 2, 50.00, 30.00));
    report.addRecord(SalesRecord("SKU-1001", 5, 100.00, 60.00));
    report.addRecord(SalesRecord("SKU-4992", 1, 25.00, 15.00));

    std::cout << "\n";
    report.print();
    return 0;
}
