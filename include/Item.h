// SHARED BASE CLASS - owned by Team Lead. Do NOT edit without telling the team.
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    std::string sku;
    std::string name;
    double price;

public:
    Item(const std::string& sku, const std::string& name, double price);
    virtual ~Item() {}

    std::string getSku() const;
    std::string getName() const;
    double getPrice() const;

    virtual std::string getType() const = 0;   // "Physical" or "Digital"
    virtual void display() const = 0;
};

#endif
