// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header.hpp>

TEST(Example, EmptyTest) {
    auto curr_path = boost::filesystem::current_path();
    std::string str_path = curr_path.c_str();
    str_path += string("misc/ftp");
    fsystem test;
    test.start(str_path.c_str());
    EXPECT_EQ(test.number_of("bcs", 122223), 46);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


