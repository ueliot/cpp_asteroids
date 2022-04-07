cmake_minimum_required(VERSION 3.0.0)
project(prueba VERSION 0.1.0)

#add_compile_options (-std=c++11 -Wall)
# set (CMAKE_CXX_FLAGS "-std=c++11 -Wall -municode ${CMAKE_CXX_FLAGS}")

include(CTest)
enable_testing()

add_executable(prueba main.cpp miniwin.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
