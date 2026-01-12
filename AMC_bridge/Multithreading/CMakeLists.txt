cmake_minimum_required(VERSION 3.10)

Project(threading)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(target_name test)

set(Sources
    #01.cpp
    #02.cpp
    #03.cpp
    04.cpp
)

add_executable(${target_name} ${Sources})
target_link_libraries(${target_name} pthread)