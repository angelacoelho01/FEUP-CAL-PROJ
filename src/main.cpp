#include "util/Time.h"

#include <iostream>

int main() {
    Time time(23, 30);
    Time time2(0, 30);
    std::cout << time + time2 << std::endl;
    return 0;
}
