cmake_minimum_required(VERSION 3.28)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

include(TestScript)

# Use git version detect to obtain a project version based on tags
include(GitVersionDetect)
set(PROJECT_VERSION_MAJOR ${GITVERSIONDETECT_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${GITVERSIONDETECT_VERSION_MINOR})
set(PROJECT_VERSION_PATCH ${GITVERSIONDETECT_VERSION_PATCH})
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

project(ip_filter_hw VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

include_directories(src)

add_executable(ip_filter 
    src/main.cpp
    # src/ip_filter.cpp
)

add_library(ip_filter_lib STATIC
    src/ip_filter.cpp
    # src/ip_filter.cpp
)

set_target_properties(ip_filter PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(ip_filter
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(ip_filter PRIVATE
    ip_filter_lib 
)

add_subdirectory(tests)
# add_subdirectory(src)

# enable_testing()

# add_executable(run_tests tests.cpp)

# set_target_properties(run_tests PROPERTIES
#     CXX_STANDARD 14
#     CXX_STANDARD_REQUIRED ON
# )

# target_link_libraries(
#     run_tests 
#     GTest::gtest_main 
#     ip_filter_hw
# )

# add_test(run_tests run_tests)

# include(GoogleTest)
# gtest_discover_tests(run_tests)


include(CTest)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
