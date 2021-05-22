#ifndef SRC_VAN_H
#define SRC_VAN_H

#include "../order/Order.h"
#include "../../util/Time.h"

#include <vector>

class Van {
public:
    Van(Van const &van);
    Van(std::string &driver, int capacity, Time deliveryTime);

    std::string getDriver() const;
    int getCapacity() const;
    Time getDeliveryTime() const;
    std::vector<Order> getOrders() const;

    void setDriver(std::string &driver);
    void setCapacity(int capacity);
    void setDeliveryTime(Time deliveryTime);
    void addOrder(const Order& order);
    void clearOrders();
    void sortOrders();
    void eraseInvalidOrders( std::vector<Order> &invalidOrders);

private:
    std::string _driver;
    int _capacity;
    Time _deliveryTime;
    std::vector<Order> _orders;

};

#endif //SRC_VAN_H
