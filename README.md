# Restaurant Billing System

A simple and easy-to-use restaurant billing system built in C++ with organized file structure.

## Features

- **Menu Management**: Pre-loaded menu with different categories (Appetizers, Main Course, Beverages, Desserts)
- **Order Management**: Add/remove items from current order
- **Bill Generation**: Automatic calculation with tax and service charges
- **User-Friendly Interface**: Simple console-based menu system
- **Organized Code Structure**: Separated into multiple files for better maintainability

## Project Structure

```
restaurant-billing-system/
├── include/                    # Header files (.h)
│   ├── MenuItem.h             # Menu item definition
│   ├── OrderItem.h            # Order item definition
│   └── RestaurantBillingSystem.h  # Main system definition
├── src/                       # Implementation files (.cpp)
│   ├── MenuItem.cpp           # MenuItem implementation
│   ├── OrderItem.cpp          # OrderItem implementation
│   └── RestaurantBillingSystem.cpp  # Main system implementation
├── main.cpp                   # Main application file
├── CMakeLists.txt            # Build configuration
└── README.md                 # This file
```

## Menu Items

### Appetizers

- Chicken Wings - $8.99
- Mozzarella Sticks - $6.99
- Caesar Salad - $7.99

### Main Course

- Grilled Chicken - $15.99
- Beef Burger - $12.99
- Fish & Chips - $14.99
- Pasta Carbonara - $13.99
- Pizza Margherita - $11.99

### Beverages

- Coca Cola - $2.99
- Fresh Juice - $4.99
- Coffee - $3.99
- Tea - $2.49

### Desserts

- Chocolate Cake - $5.99
- Ice Cream - $4.99
- Cheesecake - $6.99

## How to Build and Run

### Prerequisites

- C++ compiler (g++, clang++, or Visual Studio)
- CMake (optional, but recommended)

### Building with CMake

```bash
mkdir build
cd build
cmake ..
make
./billing_system
```

### Building with g++

```bash
g++ -std=c++11 -I include -o billing_system main.cpp src/*.cpp
./billing_system
```

### Building with Visual Studio

```bash
cl /EHsc /I include main.cpp src\*.cpp
billing_system.exe
```

## How to Use

1. **Run the program**
2. **View Menu** - See all available items
3. **Add Items** - Enter item ID and quantity
4. **View Order** - Check current order
5. **Remove Items** - Remove items if needed
6. **Generate Bill** - Get final bill with tax and service charges
7. **Clear Order** - Start fresh order
8. **Exit** - Close the program

## Features Explained

- **Tax**: 10% on subtotal
- **Service Charge**: 5% on subtotal
- **Order Management**: Add multiple quantities, update existing items
- **Bill Formatting**: Professional receipt-style output
- **Code Organization**: Separated classes for better maintainability

## Code Organization Benefits

1. **Separation of Concerns**: Each class has a specific responsibility
2. **Easy Maintenance**: Modify one file without affecting others
3. **Reusability**: Classes can be used in other projects
4. **Readability**: Clean, organized code structure
5. **Collaboration**: Multiple developers can work on different files

## Example Usage

```
Welcome to Restaurant Billing System!

========================================
     RESTAURANT BILLING SYSTEM
========================================
1. View Menu
2. Add Item to Order
3. View Current Order
4. Remove Item from Order
5. Generate Bill
6. Clear Order
7. Exit
========================================
Enter your choice (1-7): 1
```

This is a complete, working restaurant billing system that demonstrates C++ concepts like classes, vectors, file organization, and user interface design!
