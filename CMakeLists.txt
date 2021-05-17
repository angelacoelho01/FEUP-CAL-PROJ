cmake_minimum_required(VERSION 3.19)
project(src)

set(CMAKE_CXX_STANDARD 14)

add_executable(src  src/main.cpp
        src/util/Time.cpp
        src/model/client/Client.cpp src/model/order/Order.cpp
        src/model/exception/Time_Exception.cpp src/model/van/Van.cpp src/model/van/Van.h)