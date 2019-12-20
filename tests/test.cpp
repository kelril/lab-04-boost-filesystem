// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header.hpp>

TEST(Example, EmptyTest) {
    fsystem test;
    test.start("./../misc/ftp/");
    EXPECT_EQ(test.number_of("bcs", 122223), 46);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


