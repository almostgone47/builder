cmake_minimum_required(VERSION 3.25)
project(builders)

set(CMAKE_CXX_STANDARD 17)

add_executable(builders extra_builders.cpp builder.h builder.cpp linkedlist.h linkedlist.cpp request.h request.cpp stack.cpp stack.h structuretype.cpp structuretype.h buildermgr.cpp buildermgr.h extra_builders.cpp)
