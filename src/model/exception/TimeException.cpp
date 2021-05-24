#include "TimeException.h"

InvalidTime::InvalidTime(const std::string& time) :
        std::logic_error(time + " is not a valid time!"){
}