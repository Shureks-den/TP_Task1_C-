#include "gtest/gtest.h"
#include <iostream>
#include <fstream>

TEST(Test_algorithm, comparison) {
    std::ifstream ifs("../build/test/got.txt");
    std::string got;
    ifs >> got;

    std::ifstream ifs2("../expected.txt");
    std::string expected;
    ifs >> expected;

    ifs.close();
    ifs2.close();
    ASSERT_STREQ(got.c_str(), expected.c_str());
}