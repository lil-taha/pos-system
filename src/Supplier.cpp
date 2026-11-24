#include "Supplier.h"
#include <iostream>

// ---------- Supplier ----------
Supplier::Supplier(int id, const std::string& name, const std::string& contact)
    : id(id), name(name), contact(contact) {}

std::string Supplier::getName() const { return name; }

void Supplier::display() const {
    std::cout << "Supplier #" << id << " | " << name << " | " << contact << "\n";
}

// ---------- PurchaseOrder ----------
PurchaseOrder::PurchaseOrder(int poNumber, const std::string& sku, int quantity)
    : poNumber(poNumber), sku(sku), quantity(quantity), delivered(false) {}

int PurchaseOrder::getPoNumber() const { return poNumber; }
std::string PurchaseOrder::getSku() const { return sku; }
int PurchaseOrder::getQuantity() const { return quantity; }
void PurchaseOrder::markDelivered() { delivered = true; }
bool PurchaseOrder::isDelivered() const { return delivered; }

void PurchaseOrder::display() const {
    std::cout << "PO #" << poNumber << " | " << sku << " | qty " << quantity
              << " | " << (delivered ? "Delivered" : "Pending") << "\n";
}

// ---------- PurchaseOrderManager ----------
PurchaseOrderManager::PurchaseOrderManager(int firstPoNumber) : nextPoNumber(firstPoNumber) {}

int PurchaseOrderManager::checkAndGenerate(const PhysicalProduct& product) {
    if (!product.isBelowThreshold()) return 0;
    int qty = product.getReorderThreshold() * 2;   // simple rule: order twice the threshold
    orders.push_back(PurchaseOrder(nextPoNumber, product.getSku(), qty));
    return nextPoNumber++;
}

bool PurchaseOrderManager::receiveDelivery(int poNumber, Warehouse& warehouse) {
    for (auto& po : orders) {
        if (po.getPoNumber() == poNumber && !po.isDelivered()) {
            PhysicalProduct* p = warehouse.findBySku(po.getSku());
            if (p == nullptr) return false;
            p->addStock(po.getQuantity());
            po.markDelivered();
            return true;
        }
    }
    return false;
}

void PurchaseOrderManager::displayAll() const {
    for (const auto& po : orders) po.display();
}
