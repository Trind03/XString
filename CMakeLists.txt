cmake_minimum_required(VERSION 3.29)
project(XString)

add_compile_definitions(Debug=true)
add_compile_options(-std=c++20)
add_subdirectory(googletest)
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/testing
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}

)

add_executable(
    ${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/src/xstring.cpp
    ${CMAKE_SOURCE_DIR}/testing/main.cpp
)

target_link_libraries(${PROJECT_NAME} gtest gtest_main)