#include "FilesReader.h"

#include <fstream>

std::vector<Van> fileReader::getVansFromFile() {
    std::vector<Van> vans;

    std::ifstream ifs("data/vans/fleet.txt");
    if(!ifs.is_open()) return vans;

    int N;
    ifs >> N;

    std::string driver;
    int capacity, h, m;
    for (int i = 0 ; i < N; i++) {
        ifs >> driver >> capacity >> h >> m;
        vans.push_back(Van(driver, capacity, Time(h, m)));
    }

    return vans;
}

std::vector<Client> fileReader::getClientsFromFile() {
    std::vector<Client> clients;

    std::ifstream ifs("data/clients/clients.txt");
    if(!ifs.is_open()) return clients;

    int N;
    ifs >> N;

    std::string nif, name;
    int phoneNumber;
    for (int i = 0 ; i < N; i++) {
        ifs >> nif >> name >> phoneNumber;
        clients.push_back(Client(nif, name, phoneNumber));
    }

    return clients;
}

Client fileReader::findClientByNif(const std::vector<Client>& clients, const std::string& nif) {
    for (Client c : clients) {
        if (c.getNif() == nif) return c;
    }

    return Client();
}

std::vector<Order> fileReader::getOrdersFromFile(const std::string& fileName, std::vector<Client> clients) {
    std::vector<Order> orders;

    std::ifstream ifs("data/orders/" + fileName);
    if(!ifs.is_open()) return orders;

    int N;
    ifs >> N;

    std::string clientNif;
    int node, quantity, h, m;
    for (int i = 0 ; i < N; i++) {
        ifs >> node >> clientNif >> quantity >> h >> m;
        Client c = findClientByNif(clients, clientNif);
        orders.push_back(Order(node, c, quantity, Time(h, m)));
    }

    return orders;
}