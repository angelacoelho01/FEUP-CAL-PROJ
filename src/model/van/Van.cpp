#include "Van.h"

Van::Van(Van const &van) {
    _driver = van.getDriver();
    _capacity = van.getCapacity();
    _deliveryTime = van.getDeliveryTime();
    _orders = van.getOrders();
}

Van::Van(std::string &driver, int capacity, Time deliveryTime)
        : _driver(driver), _capacity(capacity), _deliveryTime(deliveryTime) { }

std::string Van::getDriver() const {
    return this->_driver;
}

int Van::getCapacity() const {
    return this->_capacity;
}

Time Van::getDeliveryTime() const{
    return this->_deliveryTime;
}

std::vector<Order> Van::getOrders() const {
    return this->_orders;
}

void Van::setDriver(std::string &driver) {
    this->_driver = driver;
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
