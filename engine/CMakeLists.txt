cmake_minimum_required(VERSION 3.10)

project(XALGameEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include")
set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")

include_directories(
    ${INCLUDE_PATH}
)

file(
    GLOB_RECURSE
    SOURCES
    ${SOURCE_PATH}/*
)
