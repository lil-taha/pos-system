// MODULE 2a - Discounts (Ali)  -> Polymorphism
// TODO (Ali): implement in src/Discount.cpp
#ifndef DISCOUNT_H
#define DISCOUNT_H

class DiscountStrategy {
public:
    virtual ~DiscountStrategy() {}
    virtual double applyDiscount(double amount) const = 0;   // returns amount AFTER discount
};

class FlatDiscount : public DiscountStrategy {
    double value;
public:
    explicit FlatDiscount(double value);
    double applyDiscount(double amount) const override;
};

class PercentageDiscount : public DiscountStrategy {
    double percent;
public:
    explicit PercentageDiscount(double percent);
    double applyDiscount(double amount) const override;
};

class BuyOneGetOne : public DiscountStrategy {
public:
    double applyDiscount(double amount) const override;
};

#endif
