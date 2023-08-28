cmake_minimum_required(VERSION 3.23)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(DesignPatterns main.cpp)
add_executable(singleton.cpp singleton.cpp)
add_executable(simpleFactory.cpp simpleFactory.cpp)
add_executable(factory.cpp factory.cpp)
add_executable(abstractFactory.cpp abstractFactory.cpp)