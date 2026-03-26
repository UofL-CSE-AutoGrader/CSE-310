#include "HelloWorld.h"

#include <gtest/gtest.h>
#include <sstream>

TEST(HelloWorld, DefaultConstructor_InitialStateIsEmpty) {
    HelloWorld hw;
    EXPECT_EQ(hw.firstName(), "");
    EXPECT_EQ(hw.lastName(), "");
}

TEST(HelloWorld, SettersAndGetters_Work) {
    HelloWorld hw;
    hw.firstName("Donald");
    hw.lastName("Knuth");

    EXPECT_EQ(hw.firstName(), "Donald");
    EXPECT_EQ(hw.lastName(), "Knuth");
}

TEST(HelloWorld, StreamOutput_FormatsAsExpected) {
    HelloWorld hw;
    hw.firstName("Alan");
    hw.lastName("Turing");

    std::ostringstream oss;
    oss << hw;

    EXPECT_EQ(oss.str(), "Hello World! I was created by Alan Turing.");
}
