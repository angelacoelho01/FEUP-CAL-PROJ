#include "Client.h"

Client::Client() : _phoneNumber(0) { }

Client::Client(std::string& nif, std::string& name, int phoneNumber) :
            _nif(nif), _name(name), _phoneNumber(phoneNumber) { }

std::string Client::getNif() const {
    return this->_nif;
}

std::string Client::getName() const {
    return this->_name;
}

int Client::getPhoneNumber() const {
    return this->_phoneNumber;
}

void Client::setName(std::string &name) {
    this->_name = name;
}

void Client::setPhoneNumber(int phoneNumber) {
    this->_phoneNumber = phoneNumber;
}
