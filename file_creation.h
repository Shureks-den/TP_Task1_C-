#pragma once
#include <stdio.h>
#include <stdlib.h>

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

FILE* create_new_database(FILE* info, char filename[]);  // создаем новый файл
FILE* add_to_existing_data_base(FILE *database, char filename[]);  // дополняем существующий файл
main_list_t* read_from_database(char filename[]);  // формируем структуру
