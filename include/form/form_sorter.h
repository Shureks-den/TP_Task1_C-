#pragma once
#include <string.h>
#include "file_creation.h"

main_list_t* initialise_main_list(form_t* element);
main_list_t* add_elem_to_main_structure(form_t* element, main_list_t* head);
form_list_t* insert_form(form_list_t* head, form_t* element);

form_list_t* copy_data(form_list_t* pre_current, form_list_t* current, form_t* element);
int print_form_structure(main_list_t* head);
int print_info(form_list_t get_data);
int clear_everything(main_list_t* head);
