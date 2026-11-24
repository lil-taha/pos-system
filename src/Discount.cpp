#include "Discount.h"

// ---------- FlatDiscount: subtract a fixed amount ----------
FlatDiscount::FlatDiscount(double value) : value(value) {}

double FlatDiscount::applyDiscount(double amount) const {
    double result = amount - value;
    return result < 0 ? 0 : result;       // never go below zero
}

// ---------- PercentageDiscount: subtract a percentage ----------
PercentageDiscount::PercentageDiscount(double percent) : percent(percent) {}

double PercentageDiscount::applyDiscount(double amount) const {
    return amount - (amount * percent / 100.0);
}

// ---------- BuyOneGetOne: simple version, pay for half of the items ----------
double BuyOneGetOne::applyDiscount(double amount) const {
    return amount / 2.0;
}
