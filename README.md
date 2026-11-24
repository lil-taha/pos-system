# Multi-Store Inventory & POS System (C++ OOP Project)

## Team
| Role | Name | Branch | Module |
|---|---|---|---|
| Team Lead | Taha Malik | `feature/inventory-supplier` | Product & Inventory Registry, Supplier & Purchase Order |
| Member 2 | Ali Ul Haq | `feature/billing-checkout` | Billing & Checkout Engine (+ Discounts, Tax) |
| Member 3 | Usman Attique| `feature/payment-analytics` | Payment Gateway, Sales Analytics & Reporting |

## Folder structure
- `include/` header files (`.h`), one set per module
- `src/` implementations (`.cpp`)
- `demo/` one small demo `main` per member for Milestone 1
- `Makefile`: build with `make`, then run `./demo_inventory`, `./demo_billing`, `./demo_payment`

## Rules
1. Work only in your own files and your own branch.
2. Never edit `Item.h` / `Item.cpp` (shared, owned by the Team Lead). Ask first.
3. Commit small and often, with clear messages (e.g. `Add PercentageDiscount class`).
4. Open a Pull Request into `main` when done. The Team Lead reviews and merges.
