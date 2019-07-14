cmake_minimum_required(VERSION 2.8)

set(PROJ_NAME yaml_cpp_sample)
project(${PROJ_NAME})

find_package(yaml-cpp REQUIRED)
include_directories(${YAML_CPP_INCLUDE_DIR})

file(GLOB PROJ_SOURCE ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB PROJ_HEADER ${CMAKE_SOURCE_DIR}/src/*.h ${CMAKE_SOURCE_DIR}/src/*.hpp)

add_executable(${PROJ_NAME} ${PROJ_SOURCE} ${PROJ_HEADER})

target_link_libraries(${PROJ_NAME} ${YAML_CPP_LIBRARIES})
