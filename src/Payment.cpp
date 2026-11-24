#include "Payment.h"
#include <iostream>
#include <iomanip>

// ---------- CashPayment ----------
bool CashPayment::pay(double amount) {
    if (amount <= 0) {
        std::cout << "Cash payment rejected: invalid amount\n";
        return false;
    }
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Cash payment of $" << amount << " accepted\n";
    return true;
}

std::string CashPayment::getMethodName() const { return "Cash"; }

// ---------- CreditCardGateway (simulated authorization callback) ----------
CreditCardGateway::CreditCardGateway(const std::string& maskedCard)
    : maskedCard(maskedCard), authCode(0) {}

bool CreditCardGateway::pay(double amount) {
    static int nextAuthCode = 994821;          // simulated bank authorization numbers
    if (amount <= 0 || amount > 5000) {        // simple rule: decline invalid or very large amounts
        std::cout << "Payment Callback: CreditCardGateway -> DECLINED (" << maskedCard << ")\n";
        return false;
    }
    authCode = nextAuthCode++;
    std::cout << "Payment Callback: CreditCardGateway -> APPROVED (Auth: " << authCode << ")\n";
    return true;
}

std::string CreditCardGateway::getMethodName() const { return "Credit Card"; }

// ---------- WalletPayment ----------
WalletPayment::WalletPayment(const std::string& walletId) : walletId(walletId) {}

bool WalletPayment::pay(double amount) {
    if (amount <= 0 || amount > 2000) {        // simple wallet limit
        std::cout << "Payment Callback: Wallet " << walletId << " -> DECLINED\n";
        return false;
    }
    std::cout << "Payment Callback: Wallet " << walletId << " -> APPROVED\n";
    return true;
}

std::string WalletPayment::getMethodName() const { return "Digital Wallet"; }
