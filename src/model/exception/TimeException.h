#ifndef SRC_TIMEEXCEPTION_H
#define SRC_TIMEEXCEPTION_H

#include "../../util/Time.h"

#include <stdexcept>

class InvalidTime : public std::logic_error {
public:
    explicit InvalidTime(const std::string& time);
};

#endif //SRC_TIMEEXCEPTION_H
