cmake_minimum_required(VERSION 3.15)
project(pixel_flow)

set(CMAKE_CXX_STANDARD 23)
add_executable(${CMAKE_PROJECT_NAME}_run src/main.cpp)

# set this flag when running coverage tests in Clion
#set(CMAKE_CXX_FLAGS "--coverage")

# generate debug information
set(CMAKE_CXX_FLAGS "-g")

# ---------------
find_package(PythonLibs REQUIRED)
find_package(Boost COMPONENTS program_options log log_setup REQUIRED)
# configure_file(${CMAKE_CURRENT_SOURCE_DIR}/out.csv
#         ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
set(PROJECT_LIB ${PROJECT_LIB} ${Boost_LOG_LIBRARY} ${Boost_LOG_SETUP_LIBRARY})
# ---------------

include_directories(src)
include_directories(${PYTHON_INCLUDE_DIRS})

add_subdirectory(src)
add_subdirectory(Google_tests)

target_link_libraries(${CMAKE_PROJECT_NAME}_run ${CMAKE_PROJECT_NAME}_lib ${PYTHON_LIBRARIES} -Wl,--start-group  ${PROJECT_LIB} -Wl,--end-group)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC -fopenmp  -DBOOST_LOG_DYN_LINK")
# target_link_libraries(<your exe or lib> ${PYTHON_LIBRARIES})
