CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

all: demo_inventory demo_billing demo_payment

demo_inventory: demo/demo_inventory.cpp src/Item.cpp src/Inventory.cpp src/Supplier.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

demo_billing: demo/demo_billing.cpp src/Item.cpp src/Billing.cpp src/Discount.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

demo_payment: demo/demo_payment.cpp src/Payment.cpp src/Analytics.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f demo_inventory demo_billing demo_payment *.exe
