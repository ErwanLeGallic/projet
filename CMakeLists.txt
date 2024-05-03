cmake_minimum_required(VERSION 3.10)
project(derived_class VERSION 1.0 LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(PROJET main.cpp)

file(GLOB MYLIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/User/*.cpp")
file(GLOB MYLIB_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/User/*.hpp")
add_library(User ${MYLIB_SOURCES} ${MYLIB_HEADERS})

file(GLOB MYLIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/User/passwordManageur/*.cpp")
file(GLOB MYLIB_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/User/passwordManageur/*.hpp")
add_library(passwordManageur ${MYLIB_SOURCES} ${MYLIB_HEADERS})

target_link_libraries(PROJET PUBLIC User)
target_link_libraries(PROJET PUBLIC passwordManageur)

# specify where the executable should be installed
install(TARGETS PROJET DESTINATION bin)
