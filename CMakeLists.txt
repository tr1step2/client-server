cmake_minimum_required(VERSION 2.8)

project(FXTM-test)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=c++11)
endif()

include_directories(common)

add_subdirectory(server)
add_subdirectory(client)
