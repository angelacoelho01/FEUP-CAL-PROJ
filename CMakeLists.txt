cmake_minimum_required(VERSION 3.17)
project(feup-cal-proj)

set(CMAKE_CXX_STANDARD 14)


set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

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
        src/map/MapLoader.cpp src/map/MapLoader.h)

add_executable(application
        src/main.cpp
        src/util/Time.cpp src/util/MutablePriorityQueue.h  src/util/map/Position.cpp src/util/Utils.cpp
        src/model/order/Order.cpp src/model/exception/TimeException.cpp src/model/client/Client.cpp src/model/van/Van.cpp 
        src/graph/Edge.cpp src/graph/Graph.cpp src/graph/Vertex.cpp 
        src/model/VanDeliveryPlanner.cpp src/model/SilviosBakery.h 
        src/controller/Operations.cpp src/controller/FilesReader.cpp 
        src/util/map/MapLabel.h 
        src/util/map/MapDrawer.cpp src/util/map/MapLoader.cpp
        src/map/MapLoader.cpp src/model/exception/FileException.cpp src/model/exception/FileException.h)

target_link_libraries(application graphviewer)
