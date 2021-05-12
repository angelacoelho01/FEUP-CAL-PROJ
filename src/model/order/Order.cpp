#include "Order.h"

Order::Order(std::string& address, Client& client, const int quantity, const Time preferredTime)
                : _address(address), _client(client), _quantity(quantity), _preferredHour(preferredTime) {}

std::string Order::getAddress() const {
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

void Order::setAddress(const std::string& address) {
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

std::ostream& operator<<(std::ostream& os, const Order& order) {
    os << "(" << order.getClient().getIdNumber() << ") Address: " << order.getAddress() << " | Preferred Hour: " << order.getPreferredHour() << " | Quantity: " << order.getQuantity();
    return os;
}
