#include "RestaurantBillingSystem.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

RestaurantBillingSystem::RestaurantBillingSystem() 
    : taxRate(0.10), serviceCharge(0.05) {
    initializeMenu();
}

void RestaurantBillingSystem::initializeMenu() {
    // Appetizers
    menu.push_back(MenuItem(1, "Chicken Wings", 8.99, "Appetizers"));
    menu.push_back(MenuItem(2, "Mozzarella Sticks", 6.99, "Appetizers"));
    menu.push_back(MenuItem(3, "Caesar Salad", 7.99, "Appetizers"));
    
    // Main Courses
    menu.push_back(MenuItem(4, "Grilled Chicken", 15.99, "Main Course"));
    menu.push_back(MenuItem(5, "Beef Burger", 12.99, "Main Course"));
    menu.push_back(MenuItem(6, "Fish & Chips", 14.99, "Main Course"));
    menu.push_back(MenuItem(7, "Pasta Carbonara", 13.99, "Main Course"));
    menu.push_back(MenuItem(8, "Pizza Margherita", 11.99, "Main Course"));
    
    // Beverages
    menu.push_back(MenuItem(9, "Coca Cola", 2.99, "Beverages"));
    menu.push_back(MenuItem(10, "Fresh Juice", 4.99, "Beverages"));
    menu.push_back(MenuItem(11, "Coffee", 3.99, "Beverages"));
    menu.push_back(MenuItem(12, "Tea", 2.49, "Beverages"));
    
    // Desserts
    menu.push_back(MenuItem(13, "Chocolate Cake", 5.99, "Desserts"));
    menu.push_back(MenuItem(14, "Ice Cream", 4.99, "Desserts"));
    menu.push_back(MenuItem(15, "Cheesecake", 6.99, "Desserts"));
}

void RestaurantBillingSystem::displayMenu() const {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "                    RESTAURANT MENU" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    std::string currentCategory = "";
    for (const auto& item : menu) {
        if (item.category != currentCategory) {
            currentCategory = item.category;
            std::cout << "\n" << currentCategory << ":" << std::endl;
            std::cout << std::string(40, '-') << std::endl;
        }
        std::cout << std::setw(3) << item.id << ". " 
                  << std::setw(25) << std::left << item.name 
                  << "$" << std::fixed << std::setprecision(2) << item.price << std::endl;
    }
    std::cout << std::string(60, '=') << std::endl;
}

void RestaurantBillingSystem::displayCurrentOrder() const {
    if (currentOrder.empty()) {
        std::cout << "\nNo items in current order." << std::endl;
        return;
    }
    
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "              CURRENT ORDER" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    std::cout << std::setw(3) << "ID" << std::setw(20) << "Item" 
              << std::setw(8) << "Qty" << std::setw(10) << "Price" << std::setw(12) << "Total" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    for (const auto& item : currentOrder) {
        std::cout << std::setw(3) << item.itemId 
                  << std::setw(20) << std::left << item.name
                  << std::setw(8) << item.quantity
                  << "$" << std::setw(9) << std::fixed << std::setprecision(2) << item.price
                  << "$" << std::fixed << std::setprecision(2) << item.total << std::endl;
    }
    std::cout << std::string(50, '=') << std::endl;
}

bool RestaurantBillingSystem::addItemToOrder(int itemId, int quantity) {
    // Find the menu item
    auto it = std::find_if(menu.begin(), menu.end(), 
                          [itemId](const MenuItem& item) { return item.id == itemId; });
    
    if (it == menu.end()) {
        std::cout << "Item not found!" << std::endl;
        return false;
    }
    
    if (quantity <= 0) {
        std::cout << "Quantity must be positive!" << std::endl;
        return false;
    }
    
    // Check if item already exists in order
    auto orderIt = std::find_if(currentOrder.begin(), currentOrder.end(),
                               [itemId](const OrderItem& item) { return item.itemId == itemId; });
    
    if (orderIt != currentOrder.end()) {
        // Update existing item
        orderIt->quantity += quantity;
        orderIt->calculateTotal();
        std::cout << "Updated quantity for " << it->name << std::endl;
    } else {
        // Add new item
        OrderItem newItem(it->id, it->name, it->price, quantity);
        currentOrder.push_back(newItem);
        std::cout << "Added " << quantity << "x " << it->name << " to order" << std::endl;
    }
    
    return true;
}

bool RestaurantBillingSystem::removeItemFromOrder(int itemId) {
    auto it = std::find_if(currentOrder.begin(), currentOrder.end(),
                          [itemId](const OrderItem& item) { return item.itemId == itemId; });
    
    if (it == currentOrder.end()) {
        std::cout << "Item not found in order!" << std::endl;
        return false;
    }
    
    std::cout << "Removed " << it->name << " from order" << std::endl;
    currentOrder.erase(it);
    return true;
}

void RestaurantBillingSystem::clearOrder() {
    currentOrder.clear();
    std::cout << "Order cleared!" << std::endl;
}

double RestaurantBillingSystem::calculateSubtotal() const {
    double subtotal = 0.0;
    for (const auto& item : currentOrder) {
        subtotal += item.total;
    }
    return subtotal;
}

void RestaurantBillingSystem::generateBill() const {
    if (currentOrder.empty()) {
        std::cout << "\nNo items to bill!" << std::endl;
        return;
    }
    
    double subtotal = calculateSubtotal();
    double tax = subtotal * taxRate;
    double service = subtotal * serviceCharge;
    double total = subtotal + tax + service;
    
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "                    RESTAURANT BILL" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::setw(3) << "ID" << std::setw(20) << "Item" 
              << std::setw(8) << "Qty" << std::setw(10) << "Price" << std::setw(12) << "Total" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    
    for (const auto& item : currentOrder) {
        std::cout << std::setw(3) << item.itemId 
                  << std::setw(20) << std::left << item.name
                  << std::setw(8) << item.quantity
                  << "$" << std::setw(9) << std::fixed << std::setprecision(2) << item.price
                  << "$" << std::fixed << std::setprecision(2) << item.total << std::endl;
    }
    
    std::cout << std::string(60, '-') << std::endl;
    std::cout << std::setw(45) << "Subtotal:" << "$" << std::fixed << std::setprecision(2) << subtotal << std::endl;
    std::cout << std::setw(45) << "Tax (10%):" << "$" << std::fixed << std::setprecision(2) << tax << std::endl;
    std::cout << std::setw(45) << "Service (5%):" << "$" << std::fixed << std::setprecision(2) << service << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::setw(45) << "TOTAL:" << "$" << std::fixed << std::setprecision(2) << total << std::endl;
    std::cout << std::string(60, '=') << std::endl;
}

void RestaurantBillingSystem::displayMainMenu() const {
    std::cout << "\n" << std::string(40, '=') << std::endl;
    std::cout << "     RESTAURANT BILLING SYSTEM" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "1. View Menu" << std::endl;
    std::cout << "2. Add Item to Order" << std::endl;
    std::cout << "3. View Current Order" << std::endl;
    std::cout << "4. Remove Item from Order" << std::endl;
    std::cout << "5. Generate Bill" << std::endl;
    std::cout << "6. Clear Order" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
}

bool RestaurantBillingSystem::isOrderEmpty() const {
    return currentOrder.empty();
}

int RestaurantBillingSystem::getOrderSize() const {
    return currentOrder.size();
}
