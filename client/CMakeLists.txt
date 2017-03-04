cmake_minimum_required(VERSION 2.8)

set (PROJECT_NAME FXTM-test-client)
project(${PROJECT_NAME})

aux_source_directory(./source SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME}
    pthread
    boost_system
    boost_thread
)
