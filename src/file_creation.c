#include "../include/form/file_creation.h"
#include "../include/form/form_sorter.h"

int create_new_database(const char filename[], const int num) {
    FILE* database = NULL;
    database = fopen(filename, "wb");

    if (database == NULL) {
        exit(FAILED_FILE_OPENNING);
    }

    form_t* info = (form_t*)calloc(1, sizeof(form_t));
    if (info == NULL) {
        exit(FAILED_MEMORY_ALLOCATION);
    }

    int i = 0;
    while (i < num) {
        fscanf(stdin, "%10lu%30s%30s", &info->num, info->place, info->responsible);
        if (strlen(info->place) && strlen(info->responsible)) {  //  неправильные (неполные данные) не запишутся
            fwrite(info, sizeof(form_t), 1, database);
        }
        strcpy(info->place, "");
        strcpy(info->responsible, "");
        i++;
    }

    free(info);
    if (database != NULL) {
        if (fclose(database)) {
            return FAILED_FILE_CLOSING;
        }
    }
    return NO_ERROR;
}

int add_to_existing_data_base(const char filename[], const int num) {
    FILE* database = NULL;
    database = fopen(filename, "ab");

    if (database == NULL) {
        exit(FAILED_FILE_OPENNING);
    }

    form_t* info = (form_t*)calloc(1, sizeof(form_t));
    if (info == NULL) {
        exit(FAILED_MEMORY_ALLOCATION);
    }
    int i = 0;
    while (i < num) {
        fscanf(stdin, "%10lu%30s%30s", &info->num, info->place, info->responsible);
        if (strlen(info->place) && strlen(info->responsible)) {  //  неправильные (неполные данные) не запишутся
            fwrite(info, sizeof(form_t), 1, database);
        }
        strcpy(info->place, "");
        strcpy(info->responsible, "");
        i++;
    }

    free(info);
    if (database != NULL) {
        if (fclose(database)) {
            return FAILED_FILE_CLOSING;
        }
    }
    return NO_ERROR;
}


main_list_t* read_from_database(const char filename[]) {
    FILE* database = NULL;
    database = fopen(filename, "rb");

    if (database == NULL) {
        exit(FAILED_FILE_OPENNING);
    }

    form_t* get_data = (form_t*)malloc(sizeof(form_t));
    if (get_data == NULL) {
        exit(FAILED_MEMORY_ALLOCATION);
    }

    fread(get_data, sizeof(form_t), 1, database);
    
    main_list_t* head = NULL;
    head = initialise_main_list(get_data);

    while (fread(get_data, sizeof(form_t), 1, database) != 0) {
        head = add_elem_to_main_structure(get_data, head);
    }

    free(get_data);
    if (fclose(database)) {
        exit(FAILED_FILE_CLOSING);
    }
    return head;
}


