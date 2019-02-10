cmake_minimum_required(VERSION 3.9)
project(Linked_ptr)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,undefined")
add_executable(Linked_ptr
        #main.cpp
        linked_ptr.h
        #main2.cpp
        main3.cpp
        )