#ifndef SRC_VAN_H
#define SRC_VAN_H

#include "../order/Order.h"
#include "../../util/Time.h"

#include <vector>

class Van {
public:
    Van(int capacity, Time deliveryTime);

    int getCapacity() const;
    Time getDeliveryTime() const;
    std::vector<Order> getOrders() const;

    void setCapacity(int capacity);
    void setDeliveryTime(Time deliveryTime);
    void addOrder(const Order& order);
    void clearOrders();
private:
    int _capacity;
    Time _deliveryTime;
    std::vector<Order> _orders;
};

#endif //SRC_VAN_H
