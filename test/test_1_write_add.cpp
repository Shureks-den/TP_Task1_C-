#include <iostream>
#include "gtest/gtest.h"

extern "C" {
    #include "form/file_creation.h"
    #include "form/form_sorter.h"
}

TEST(File_test, create) {
    char filename[] = "test.bin";
    ASSERT_EQ(write_to_database(filename, "-c", 3), 0);
}

TEST(File_test, add) {
    char filename[] = "test.bin";
    ASSERT_EQ(write_to_database(filename, "-a", 3), 0);
}

