cmake_minimum_required(VERSION 3.20)

project(LUMINEX)

set(CMAKE_CXX_STANDARD 20)

add_executable(lum src/main.cpp
        src/headers/type_of_token.h
        src/headers/token.h
)