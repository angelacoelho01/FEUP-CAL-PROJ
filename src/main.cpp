#include "util/Time.h"

#include <iostream>
#include <algorithm>

#include "map/MapLoader.h"

#include <float.h>
#include <sstream>

int main() {
    MapLoader mapLoader(1644, 921);
    mapLoader.loadMap("Porto");
    return 0;
}
