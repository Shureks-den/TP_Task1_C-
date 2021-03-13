#include "gtest/gtest.h"

extern "C" {
    #include "form/file_creation.h"
    #include "form/form_sorter.h"
}

TEST(Test_structure, file_read) {
    main_list_t* head = nullptr;
    char filename[] = "test.bin";
    head = read_from_database(filename);
    ASSERT_NE(head, nullptr);
    freopen("log.txt", "w", stdout);
    //freopen("/dev/tty","w",stdout);
    ASSERT_EQ(print_everything(head), 0);
    clear_everything(head);
}
