#ifndef SRC_CLIENT_H
#define SRC_CLIENT_H
#include <string>

#include "../../util/Time.h"

// Represents a client of the bakery: identified by his nif, name and phone number
class Client {
public:
    Client();
    Client(std::string& nif, std::string& name, int phoneNumber);

    std::string getNif() const;
    std::string getName() const;
    int getPhoneNumber() const;

    void setName(std::string &name);
    void setPhoneNumber(int phoneNumber);
private:
    std::string _nif;
    std::string _name;
    int _phoneNumber;
};

#endif // SRC_CLIENT_H
