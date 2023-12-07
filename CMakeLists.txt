cmake_minimum_required(VERSION 3.20)
project(mycplus)

set(CMAKE_CXX_STANDARD 23)

add_executable(mycplus main.cpp src/foundation/type/type.cpp src/foundation/type/type.h src/foundation/string/str.cpp src/foundation/string/str.h)
