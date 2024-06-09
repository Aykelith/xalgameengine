cmake_minimum_required(VERSION 3.10)

project(Example1 VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GRAPHICS_API "VULKAN" CACHE STRING "The graphics API to use (VULKAN, DIRECTX, OPENGL)")

set(ENV{VULKAN_SDK} "C:/VulkanSDK/1.3.283.0")

find_package(Vulkan REQUIRED)

add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/../../engine"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../engine/builds"
)

include_directories(
    ${Vulkan_INCLUDE_DIRS}
    "${CMAKE_CURRENT_SOURCE_DIR}/../../engine/libs/glfw/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../engine/include"
)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Settings.in.hpp" "${CMAKE_CURRENT_SOURCE_DIR}/Settings.hpp")

add_executable(Example1 main.cpp)

target_link_libraries(Example1 PRIVATE XALGameEngine Vulkan::Vulkan)
