#ifndef SRC_TIME_EXCEPTION_H
#define SRC_TIME_EXCEPTION_H

#include "../../util/Time.h"

#include <stdexcept>

class InvalidTime : public std::logic_error {
public:
    explicit InvalidTime(const std::string& time);
};

#endif //SRC_TIME_EXCEPTION_H
