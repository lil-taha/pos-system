// MODULE 5 - Sales Analytics & Reporting (Usman)
// TODO (Usman): implement in src/Analytics.cpp
#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <string>
#include <vector>

class SalesRecord {
    std::string sku;
    int qtySold;
    double revenue;
    double cost;
public:
    SalesRecord(const std::string& sku, int qtySold, double revenue, double cost);
    double getProfit() const;
    std::string getSku() const;
    int getQtySold() const;
    double getRevenue() const;
};

class SalesReport {
    std::vector<SalesRecord> records;
public:
    void addRecord(const SalesRecord& r);
    double dailyTurnover() const;
    std::string topSellingSku() const;
    void print() const;
};

#endif
