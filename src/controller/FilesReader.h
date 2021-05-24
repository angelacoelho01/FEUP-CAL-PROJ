#ifndef SRC_FILESREADER_H
#define SRC_FILESREADER_H

#include "../model/client/Client.h"
#include "../model/order/Order.h"
#include "../model/van/Van.h"

#include <iostream>
#include <vector>

namespace fileReader {
    // Gets Bakery Van fleet
    std::vector<Van> getVansFromFile();

    // Gets Bakery Clients
    std::vector<Client> getClientsFromFile();

    // Find and return a client by his nif
    Client findClientByNif(const std::vector<Client>& clients, const std::string& nif);

    // Gets Bakery Orders set
    std::vector<Order> getOrdersFromFile(const std::string& fileName, std::vector<Client> clients);
}

#endif //SRC_FILESREADER_H
