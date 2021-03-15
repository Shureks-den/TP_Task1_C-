#pragma once
#include <stdio.h>
#include <stdlib.h>

enum error_list {
    NO_ERROR = 0,
    FAILED_FILE_OPENNING = 1,
    FAILED_FILE_CLOSING = 2,
    FAILED_MEMORY_ALLOCATION = 3,
    FAILED_MEMORY_CLEAR = 4,
    WRONG_NUM_OF_ARG = 5,
    SCANF_ERROR = 6,
    FREAD_ERROR = 7
};

typedef struct form {
    size_t num;
    char responsible[30];
    char place[30];
} form_t;

typedef struct form_list form_list_t;
struct form_list {
    form_t data;
    form_list_t* next;
};

typedef struct main_list main_list_t;
struct main_list {
    form_list_t* head;
    main_list_t* next_list;
};

int write_to_database(const char filename[], const char action[], const size_t num);  // создаем новый файл
main_list_t* read_from_database(const char filename[]);  // формируем структуру
