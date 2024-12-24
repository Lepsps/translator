cmake_minimum_required(VERSION 3.10)

set(ProjectName "translator")

project(${ProjectName})

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(gtest)

# REPORT
message( STATUS "")
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "======================================")
message( STATUS "")
message( STATUS "   Configuration: ${CMAKE_BUILD_TYPE}")
message( STATUS "")