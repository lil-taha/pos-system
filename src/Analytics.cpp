#include "Analytics.h"
#include <iostream>
#include <iomanip>
#include <map>

// ---------- SalesRecord ----------
SalesRecord::SalesRecord(const std::string& sku, int qtySold, double revenue, double cost)
    : sku(sku), qtySold(qtySold), revenue(revenue), cost(cost) {}

double SalesRecord::getProfit() const { return revenue - cost; }
std::string SalesRecord::getSku() const { return sku; }
int SalesRecord::getQtySold() const { return qtySold; }
double SalesRecord::getRevenue() const { return revenue; }

// ---------- SalesReport ----------
void SalesReport::addRecord(const SalesRecord& r) { records.push_back(r); }

double SalesReport::dailyTurnover() const {
    double total = 0;
    for (const auto& r : records) total += r.getRevenue();
    return total;
}

std::string SalesReport::topSellingSku() const {
    std::map<std::string, int> qtyBySku;       // add up quantity for each SKU
    for (const auto& r : records) qtyBySku[r.getSku()] += r.getQtySold();

    std::string best = "";
    int bestQty = 0;
    for (const auto& entry : qtyBySku) {
        if (entry.second > bestQty) {
            bestQty = entry.second;
            best = entry.first;
        }
    }
    return best;                                // empty string if there are no records
}

void SalesReport::print() const {
    double profit = 0;
    for (const auto& r : records) profit += r.getProfit();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "----- DAILY SALES REPORT -----\n";
    std::cout << "Daily turnover: $" << dailyTurnover() << "\n";
    std::cout << "Gross profit:   $" << profit << "\n";
    std::cout << "Top-selling SKU: " << topSellingSku() << "\n";
}
