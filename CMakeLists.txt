cmake_minimum_required(VERSION 3.28)

project(ip_filter_hw)

add_executable(ip_tracer ip_filter.cpp)

set_target_properties(ip_tracer PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(ip_tracer
    PRIVATE "${CMAKE_BINARY_DIR}"
)

