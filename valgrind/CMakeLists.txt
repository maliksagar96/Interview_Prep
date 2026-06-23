cmake_minimum_required(VERSION 3.20)

project(valgrind_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(target valgrid_test)

set(SOURCES
    src/main.cpp
    src/lib1.cpp
    src/lib2.cpp
)

add_executable(${target} ${SOURCES})
target_include_directories(${target} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_options(${target} PRIVATE -Wall -g)






