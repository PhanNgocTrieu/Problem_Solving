// This is just demo
#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertion) {
    // Comparing string is not equal
    EXPECT_STRNE("hello", "world");
    // Comparing equal
    EXPECT_EQ(7 * 6, 42);
}
