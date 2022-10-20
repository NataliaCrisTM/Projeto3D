cmake_minimum_required(VERSION 3.5)

project(Sculptor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

add_executable(Sculptor main.cpp voxel.cpp sculptor.cpp)

install(TARGETS Sculptor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

set(CMAKE_CXX_FLAGS "-g")
