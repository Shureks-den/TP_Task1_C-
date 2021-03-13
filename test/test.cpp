#include "gtest/gtest.h"
#include <iostream>

extern "C" {
    #include "form/file_creation.h"
    #include "form/form_sorter.h"
}

TEST(File_test, create) {
    char filename[] = "test.bin";
    ASSERT_EQ(create_new_database(filename, 3), 0);
}

TEST(File_test, add) {
    char filename[] = "test.bin";
    ASSERT_EQ(add_to_existing_data_base(filename, 3), 0);
}

