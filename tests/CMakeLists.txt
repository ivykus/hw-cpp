option(INSTALL_GMOCK "Install Googletest's GMock?" OFF)
option(INSTALL_GTEST "Install Googletest's GTest?" OFF)
 
include(FetchContent)
FetchContent_Declare(
    googletest
    # URL https://github.com/google/googletest/archive/03597a01ee50e    d33e9dfd640b249b4be3799d395.zip
    URL https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz
)


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(run_tests 
    tests.cpp
    # ../src/ip_filter.cpp
    # ip_filter.cpp 
)

set_target_properties(run_tests PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(
    run_tests 
    GTest::gtest_main 
    GTest::gmock
    ip_filter_lib
)

add_test(run_tests run_tests)

include(GoogleTest)
gtest_discover_tests(run_tests)
