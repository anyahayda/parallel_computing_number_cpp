cmake_minimum_required(VERSION 3.8)
project(lab_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(lab_2 ${SOURCE_FILES})
find_package(Threads REQUIRED)
target_link_libraries(lab_2 Threads::Threads)