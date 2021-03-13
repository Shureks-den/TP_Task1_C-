#include "gtest/gtest.h"
#include <iostream>
#include <fstream>

TEST(Test_algorithm, comparison) {
    
    std::ifstream t("../build/test/got.txt");
    char got[2000];
    t >> got;

    std::ifstream t2("../expected.txt");
    char expected[2000];
    t2 >> expected;

    std::ofstream x ("../result.txt");
    x << got;
    x << strlen(expected);

    t.close();
    t2.close();
    ASSERT_STREQ(got, expected);
}