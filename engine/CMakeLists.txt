cmake_minimum_required(VERSION 3.10)

project(XALGameEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(glm_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/glm/install/share/glm")
set(glfw3_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/install/lib/cmake/glfw3")
set(ENV{VULKAN_SDK} "C:/VulkanSDK/1.3.283.0")

find_package(Vulkan REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glfw3 3.3 REQUIRED)

option(XALGE_IS_PRODUCTION "ON for production build" OFF)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/include/XALGameEngine/Global.in.hpp" "${CMAKE_CURRENT_SOURCE_DIR}/include/XALGameEngine/Global.hpp")

set(INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include")
set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")

include_directories(
    ${Vulkan_INCLUDE_DIRS}
    ${INCLUDE_PATH}
)

file(
    GLOB_RECURSE
    SOURCES
    ${SOURCE_PATH}/*
)

message("SOURCES:" ${SOURCES})
add_library(XALGameEngine STATIC ${SOURCES})

set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

target_link_libraries(XALGameEngine PRIVATE glm::glm glfw Vulkan::Vulkan)
