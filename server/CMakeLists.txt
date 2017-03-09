cmake_minimum_required(VERSION 2.8)

project(FXTM-test-server)

aux_source_directory(./source SRC_LIST)

include_directories(${BOOST_PATH}
                    ${CMAKE_CURRENT_SOURCE_DIR}/../common/)
link_directories(${BOOST_LIB_PATH})

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME}
    boost_system
    boost_date_time
    boost_regex
    pthread
)
