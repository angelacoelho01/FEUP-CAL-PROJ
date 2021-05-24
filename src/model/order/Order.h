#ifndef SRC_ORDER_H
#define SRC_ORDER_H

#include <iostream>
#include <string>
#include <ctime>

#include "../../util/Time.h"
#include "../client/Client.h"

#include <string>
#include <iostream>

class Order {
public:
    Order(int address, Client& client, int quantity, Time preferredTime) ;

    int getAddress() const;
    Client getClient() const;
    int getQuantity() const;
    Time getPreferredHour() const;

    void setAddress(const int address);
    void setClient(const Client& client);
    void setQuantity(int quantity);
    void setPreferredHour(Time preferredTime);

    bool operator<(const Order &order) const;
    friend std::ostream& operator<<(std::ostream& os, const Order& order);
private:
    int _address; // node id
    Client _client;
    int _quantity; // number of breads
    Time _preferredHour;
};


#endif // SRC_ORDER_H
