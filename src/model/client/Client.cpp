#include "Client.h"


Client::Client(std::string& name, int phoneNumber, std::string& idNumber) :
            _name(name), _phoneNumber(phoneNumber), _idNumber(idNumber){
}

std::string Client::getName() const { return _name; }

std::string Client::getIdNumber() const { return _idNumber; }

int Client::getPhoneNumber() const { return _phoneNumber; }

void Client::changePhoneNumber(int const phoneNumber) { this->_phoneNumber= phoneNumber; }


