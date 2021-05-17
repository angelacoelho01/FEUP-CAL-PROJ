#include "Van.h"

Van::Van(int capacity, Time deliveryTime) : _capacity(capacity), _deliveryTime(deliveryTime) { }

int Van::getCapacity() const {
    return this->_capacity;
}

Time Van::getDeliveryTime() const{
    return this->_deliveryTime;
}

std::vector<Order> Van::getOrders() const {
    return this->_orders;
}

void Van::setCapacity(const int capacity){
    this->_capacity = capacity;
}

void Van::setDeliveryTime(const Time deliveryTime){
    this->_deliveryTime = deliveryTime;
}

void Van::addOrder(const Order& order) {
    this->_orders.push_back(order);
}

void Van::clearOrders() {
    this->_orders.clear();
}
