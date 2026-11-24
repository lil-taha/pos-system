#include "Item.h"

Item::Item(const std::string& sku, const std::string& name, double price)
    : sku(sku), name(name), price(price) {}

std::string Item::getSku() const { return sku; }
std::string Item::getName() const { return name; }
double Item::getPrice() const { return price; }
