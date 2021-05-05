#include "util/Time.h"

#include <iostream>

int main() {
    Time time(25, 30);
    std::cout << time.getTime() << std::endl;
    return 0;
}
