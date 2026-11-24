// MODULE 4 - Payment Gateway Integration (Usman)  -> Abstraction + Polymorphism
// TODO (Usman): implement in src/Payment.cpp
#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

class PaymentProcessor {
public:
    virtual ~PaymentProcessor() {}
    virtual bool pay(double amount) = 0;
    virtual std::string getMethodName() const = 0;
};

class CashPayment : public PaymentProcessor {
public:
    bool pay(double amount) override;
    std::string getMethodName() const override;
};

class CreditCardGateway : public PaymentProcessor {
    std::string maskedCard;
    int authCode;
public:
    explicit CreditCardGateway(const std::string& maskedCard);
    bool pay(double amount) override;
    std::string getMethodName() const override;
};

class WalletPayment : public PaymentProcessor {
    std::string walletId;
public:
    explicit WalletPayment(const std::string& walletId);
    bool pay(double amount) override;
    std::string getMethodName() const override;
};

#endif
