#include <iostream>
#include <fstream>
#include <string>

#include "gtest/gtest.h"

TEST(Test_algorithm, comparison) {
    std::ifstream t("got.txt");
    std::string got;
    std::string buff;
    while (t) {
        getline(t, buff);
        got += buff;
    }


    std::ifstream t2("../../expected.txt");
    std::string expected;
    while (t2) {
        getline(t2, buff);
        expected += buff;
    }

    t.close();
    t2.close();
    ASSERT_STREQ(got.c_str(), expected.c_str());
}
