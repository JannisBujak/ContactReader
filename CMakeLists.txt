cmake_minimum_required(VERSION 3.10)
project(ContactReader)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_executable(ContactReader
        src/Contact.cpp
        src/Contact.h
        src/Register.cpp
        src/Register.h
        main.cpp)
