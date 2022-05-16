cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(BUILD_TESTS "Build tests" OFF)
project(test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

include_directories(PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/banking)
add_library(banking STATIC ${CMAKE_CURRENT_SOURCE_DIR}/../banking/Transaction.cpp 
                           ${CMAKE_CURRENT_SOURCE_DIR}/../banking/Account.cpp)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  add_executable(check test1.cpp test2.cpp)
  target_link_libraries(check banking gtest_main)
  add_test(NAME check COMMAND check)
endif()
