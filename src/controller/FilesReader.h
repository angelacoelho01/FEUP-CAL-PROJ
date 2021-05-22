#ifndef SRC_FILESREADER_H
#define SRC_FILESREADER_H

#include "../model/van/Van.h"
#include "../model/client/Client.h"
#include "../model/order/Order.h"

#include <iostream>
#include <vector>

namespace fileReader {
    std::vector<Van> getVansFromFile();

    std::vector<Client> getClientsFromFile();

    Client findClientByNif(const std::vector<Client>& clients, const std::string& nif);

    std::vector<Order> getOrdersFromFile(const std::string& fileName, std::vector<Client> clients);
}

#endif //SRC_FILESREADER_H
