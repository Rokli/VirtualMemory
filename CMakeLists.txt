cmake_minimum_required(VERSION 3.27)
project(VirtualMemory)

set(CMAKE_CXX_STANDARD 23)

add_executable(VirtualMemory main.cpp
        VirtualMemoryManagement.cpp
        VirtualMemoryManagement.h
        Page.cpp
        Page.h
)
