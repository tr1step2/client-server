cmake_minimum_required(VERSION 2.8)

project(FXTM-test)

add_compile_options(-std=c++11)

add_subdirectory(server)
add_subdirectory(client)
