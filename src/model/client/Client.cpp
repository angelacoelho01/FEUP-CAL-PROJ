#include "Client.h"


Client::Client(std::string name, int phoneNumber, std::string idNumber) :
            _name(name), _phoneNumber(phoneNumber), _idNumber(idNumber){
}

std::string Client::getName() { return _name; }

std::string Client::getIdNumber() { return _idNumber; }

int Client::getPhoneNumber() { return _phoneNumber; }

void Client::changePhoneNumber(int phoneNumber) { this->_phoneNumber= phoneNumber; }


