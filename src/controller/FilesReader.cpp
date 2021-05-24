#include "FilesReader.h"
#include "../model/exception/FileException.h"

#include <fstream>
#include <sstream>

std::vector<Van> fileReader::getVansFromFile() {
    std::string path = "../resources/data/vans/fleet.txtt";

    std::ifstream ifs(path);
    if (!ifs.is_open()) throw FileNotFound(path);

    std::vector<Van> vans;

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
    std::string path = "../resources/data/clients/clients.txt";

    std::ifstream ifs(path);
    if (!ifs.is_open()) throw FileNotFound(path);

    std::vector<Client> clients;

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
    std::stringstream ss;
    ss << "../resources/data/orders/" << fileName;
    std::string path = ss.str();

    std::ifstream ifs(path);
    if (!ifs.is_open()) throw FileNotFound(path);

    std::vector<Order> orders;

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