#include "util/Time.h"

#include <iostream>
#include <algorithm>

#include "map/MapLoader.h"

#include <float.h>
#include <sstream>

int main() {
    MapLoader mapLoader(1600, 900);
    mapLoader.loadMap("Coimbra");
    return 0;
}
