#ifndef SRC_CLIENT_H
#define SRC_CLIENT_H
#include <string>

#include "../order/Order.h"
#include "../../util/Time.h"


class Client {
    public:
    Client( std::string name, int phoneNumber, std::string idNumber);
    std::string getName();
    int getPhoneNumber();
    std::string getIdNumber();
    void changePhoneNumber(int phoneNumber);


private:
    std::string _name;
    int _phoneNumber;
    std::string _idNumber;
};

#endif //SRC_CLIENT_H
