#include "gtest/gtest.h"

extern "C" {
    #include "form/file_creation.h"
    #include "form/form_sorter.h"
}


TEST(Test_structure, wrong_file_create) {
    char filename[] = "";
    ASSERT_EQ(write_to_database(filename, "-a", 3), FAILED_FILE_OPENNING);
}

TEST(Test_structure, wrong_file_read) {
    char filename[] = "nottest.bin";
    ASSERT_EQ(write_to_database(filename, "-a", 3), SCANF_ERROR);
}

TEST(Test_print, null_head) {
    main_list_t* head = nullptr;
    ASSERT_EQ(print_form_structure(head), PRINT_ERROR);
}

TEST(Test_add, null_element) {
    form_t* element = nullptr;
    main_list_t* head = nullptr;
    ASSERT_EQ(add_elem_to_main_structure(element, head), nullptr);
}

TEST(Test_structure, empty_file_read) {
    main_list_t* head = nullptr;
    char filename1[] = "notest.bin";
    head = read_from_database(filename1);
    ASSERT_EQ(head, nullptr);
    char filename2[] = "nottest.bin";
    head = read_from_database(filename2);
    ASSERT_EQ(head, nullptr);
}

TEST(Test_strutuce, initialise_with_NULL) {
    main_list_t* head = nullptr;
    head = initialise_main_list(NULL);
    ASSERT_EQ(head, nullptr);
}

TEST(Test_structure, file_read) {
    main_list_t* head = nullptr;
    char filename[] = "test.bin";
    head = read_from_database(filename);
    ASSERT_NE(head, nullptr);
    freopen("got.txt", "w", stdout);
    ASSERT_EQ(print_form_structure(head), 0);
    clear_everything(head);
    fclose(stdout);
}
