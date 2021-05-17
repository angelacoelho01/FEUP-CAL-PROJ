#ifndef SRC_VAN_H
#define SRC_VAN_H

#include "../../util/Time.h"

class Van {
public:
    Van(int capacity, Time deliveryTime);

    int getCapacity() const;
    Time getDeliveryTime() const;

    void setCapacity(const int capacity);
    void setDeliveryTime(const Time deliveryTime);
private:
    int _capacity;
    Time _deliveryTime;
    // grafo com as encomendas pelas quais é responsavel
};

#endif //SRC_VAN_H
