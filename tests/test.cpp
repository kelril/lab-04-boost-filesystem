// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header.hpp>

using boost::filesystem::all_all;

TEST(Example, EmptyTest) {
    auto _path = boost::filesystem::path{"./../misc/ftp"};
    fsystem test;
    test.start(_path);
    EXPECT_TRUE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


