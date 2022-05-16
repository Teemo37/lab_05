cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(task1)

add_library(banking STATIC ${CMAKE_CURRENT_SOURCE_DIR}/Account.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Transaction.cpp)
