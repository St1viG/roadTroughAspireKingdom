cmake_minimum_required(VERSION 3.27)
project(roadTroughAspireKingdom)

set(CMAKE_CXX_STANDARD 17)

add_executable(roadTroughAspireKingdom
        src/main.cpp
        include/Heap.h
        src/heap.cpp
        include/Node.h
        src/node.cpp
        src/functions.cpp
        include/functions.h)
