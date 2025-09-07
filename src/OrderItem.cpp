#include "OrderItem.h"

OrderItem::OrderItem(int itemId, const std::string& name, double price, int quantity)
    : itemId(itemId), name(name), price(price), quantity(quantity) {
    calculateTotal();
}

void OrderItem::calculateTotal() {
    total = price * quantity;
}
