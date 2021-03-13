#include "gtest/gtest.h"
#include <iostream>
#include <fstream>
#include <string>

TEST(Test_algorithm, comparison) {
    
    std::ifstream t("/home/zennoma/Downloads/C++/Task1/build/test/got.txt");
    std::string got;
    std::string buff;
    while(t) {
        getline(t, buff);
        got += buff;
    }


    std::ifstream t2("/home/zennoma/Downloads/C++/Task1/expected.txt");
    std::string expected;
    while(t2) {
        getline(t2, buff);
        expected += buff;
    }

    t.close();
    t2.close();
    ASSERT_STREQ(got.c_str(), expected.c_str());
}