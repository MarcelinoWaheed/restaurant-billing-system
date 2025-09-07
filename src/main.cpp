#include "RestaurantBillingSystem.h"
#include <iostream>

int main() {
    RestaurantBillingSystem billingSystem;
    int choice;
    
    std::cout << "Welcome to Restaurant Billing System!" << std::endl;
    
    while (true) {
        billingSystem.displayMainMenu();
        std::cout << "Enter your choice (1-7): ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                billingSystem.displayMenu();
                break;
            }
            case 2: {
                int itemId, quantity;
                std::cout << "Enter item ID: ";
                std::cin >> itemId;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                billingSystem.addItemToOrder(itemId, quantity);
                break;
            }
            case 3: {
                billingSystem.displayCurrentOrder();
                break;
            }
            case 4: {
                int itemId;
                std::cout << "Enter item ID to remove: ";
                std::cin >> itemId;
                billingSystem.removeItemFromOrder(itemId);
                break;
            }
            case 5: {
                billingSystem.generateBill();
                break;
            }
            case 6: {
                billingSystem.clearOrder();
                break;
            }
            case 7: {
                std::cout << "Thank you for using Restaurant Billing System!" << std::endl;
                return 0;
            }
            default: {
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
            }
        }
        
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    }
    
    return 0;
}