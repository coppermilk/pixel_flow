cmake_minimum_required(VERSION 3.15)
project(pixel_flow)

set(CMAKE_CXX_STANDARD 23)
add_executable(${CMAKE_PROJECT_NAME}_run main.cpp)

# set this flag when running coverage tests in Clion
#set(CMAKE_CXX_FLAGS "--coverage")

# generate debug information
set(CMAKE_CXX_FLAGS "-g")

# ---------------
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/out.csv
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
# ---------------

include_directories(src)
add_subdirectory(src)

add_subdirectory(Google_tests)

target_link_libraries(${CMAKE_PROJECT_NAME}_run ${CMAKE_PROJECT_NAME}_lib)
