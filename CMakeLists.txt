cmake_minimum_required(VERSION 3.10)
project(projet VERSION 0.1.0 LANGUAGES C CXX)

#include(CTest)
#enable_testing()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(projet main.cpp)


#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
