cmake_minimum_required(VERSION 2.8)

project(FXTM-test)

add_subdirectory(server)
add_subdirectory(client)

include_directories(common)
