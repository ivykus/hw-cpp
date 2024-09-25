#include <gtest/gtest.h>
#include <gmock/gmock.h>

// #include "../src/lib.h"


// test change

using namespace std::literals::string_literals;

TEST(silly_test, test_test_function)
{
    EXPECT_EQ(1, 1);
}

TEST(test_gmock_setup, test_gmock_setup)
{
    std::vector<int> res{1, 2, 3};
    ASSERT_THAT(res, testing::ElementsAre(1, 2, 3));
}


