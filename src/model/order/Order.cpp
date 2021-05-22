#include "Order.h"

Order::Order(int address, Client& client, const int quantity, const Time preferredTime)
                : _address(address), _client(client), _quantity(quantity), _preferredHour(preferredTime) {}

int Order::getAddress() const {
    return this->_address;
}

Client Order::getClient() const {
    return this->_client;
}

int Order::getQuantity() const {
    return this->_quantity;
}

Time Order::getPreferredHour() const {
    return this->_preferredHour;
}

void Order::setAddress(const int address) {
    this->_address = address;
}

void Order::setClient(const Client& client) {
    this->_client = client;
}

void Order::setQuantity(const int quantity) {
    this->_quantity = quantity;
}

void Order::setPreferredHour(const Time preferredHour) {
    this->_preferredHour = preferredHour;
}

bool Order::operator<(const Order &order) const {
    return this->_preferredHour < order.getPreferredHour();
}

std::ostream& operator<<(std::ostream& os, const Order& order) {
    os << "(" << order.getClient().getNif() << ") Address: " << order.getAddress() << " | Preferred Hour: " << order.getPreferredHour() << " | Quantity: " << order.getQuantity();
    return os;
}
