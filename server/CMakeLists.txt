cmake_minimum_required(VERSION 2.8)

project(FXTM-test-server)

aux_source_directory(./source SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})