cmake_minimum_required(VERSION 3.17)
project(feup-cal-proj)

set(CMAKE_CXX_STANDARD 14)

# Build GraphViewerCpp
set(GRAPHVIEWERCPP_PATH lib/GraphViewerCpp)
add_subdirectory(${GRAPHVIEWERCPP_PATH})
include_directories(${GRAPHVIEWERCPP_PATH}/include)

add_library(feup-cal-proj
        src/main.cpp
        src/util/Time.cpp src/util/Time.h
        src/model/order/Order.cpp src/model/order/Order.h
        src/model/exception/TimeException.cpp src/model/exception/TimeException.h
        src/model/client/Client.cpp src/model/client/Client.h
        src/map/MapLoader.cpp src/map/MapLoader.h
        src/graph/Node.cpp src/graph/Node.h
        src/graph/Graph.cpp src/graph/Graph.h
        src/graph/Edge.cpp src/graph/Edge.h)

add_executable(application
        src/main.cpp
        src/model/order/Order.cpp src/model/exception/TimeException.cpp src/model/client/Client.cpp
        src/map/MapLoader.cpp
        src/graph/Node.cpp src/graph/Edge.cpp src/graph/Graph.cpp)

target_link_libraries(application graphviewer)
