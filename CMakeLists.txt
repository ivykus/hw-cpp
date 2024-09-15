cmake_minimum_required(VERSION 3.28)

# file(GLOB MODULE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/*/" LIST_DIRECTORIES true)
# list(APPEND CMAKE_MODULE_PATH "${MODULE_DIRS}")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules")

# Use git version detect to obtain a project version based on tags
include(GitVersionDetect)
set(MYPROJECT_VERSION_MAJOR ${GITVERSIONDETECT_VERSION_MAJOR})
set(MYPROJECT_VERSION_MINOR ${GITVERSIONDETECT_VERSION_MINOR})
set(MYPROJECT_VERSION_PATCH ${GITVERSIONDETECT_VERSION_PATCH})
set(MYPROJECT_VERSION ${MYPROJECT_VERSION_MAJOR}.${MYPROJECT_VERSION_MINOR}.${MYPROJECT_VERSION_PATCH})

project(ip_filter_hw)

add_executable(ip_tracer ip_filter.cpp)

set_target_properties(ip_tracer PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(ip_tracer
    PRIVATE "${CMAKE_BINARY_DIR}"
)

