#ifndef SRC_CLIENT_H
#define SRC_CLIENT_H
#include <string>

#include "../../util/Time.h"

class Client {
public:
    Client( std::string& name, int phoneNumber, std::string& idNumber);
    std::string getName() const;
    int getPhoneNumber() const;
    std::string getIdNumber() const;
    void changePhoneNumber(int phoneNumber);
private:
    std::string _name;
    int _phoneNumber;
    std::string _idNumber;
};

#endif // SRC_CLIENT_H
