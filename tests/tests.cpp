#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/ip_filter.h"

// test change

using namespace std::literals::string_literals;

TEST(silly_test, test_test_function)
{
    EXPECT_EQ(ip_filter::test_function(), 42);
}

TEST(test_gmock_setup, test_gmock_setup)
{
    std::vector<int> res{1, 2, 3};
    ASSERT_THAT(res, testing::ElementsAre(1, 2, 3));
}


// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
TEST(test_split, test_split)
{
    std::vector<std::string> exp{"11", "22"};
    // EXPECT_EQ(ip_filter::split("11.22", '.'), testing::ElementsAre("11"s, "22"s));
    EXPECT_EQ(ip_filter::split("11.22", '.'), exp);
    
}

