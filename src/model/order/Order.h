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
    Order(std::string& address, Client& client, int quantity, Time preferredTime) ;

    std::string getAddress() const;
    Client getClient() const;
    int getQuantity() const;
    Time getPreferredHour() const;

    void setAddress(const std::string& address);
    void setClient(const Client& client);
    void setQuantity(int quantity);
    void setPreferredHour(Time preferredTime);

    friend std::ostream& operator<<(std::ostream& os, const Order& order);
private:
    std::string _address;
    Client _client;
    int _quantity; // number of breads
    Time _preferredHour;
};


#endif // SRC_ORDER_H
