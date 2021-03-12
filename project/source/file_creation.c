#include "file_creation.h"
#include "form_sorter.h"

FILE* create_new_database(FILE *database, char filename[]) {
    database = fopen(filename, "wb");

    if (database == NULL) {
        exit(FAILED_FILE_OPENNING);
    }

    form_t* info = calloc(1, sizeof(form_t));
    if (info == NULL) {
        exit(FAILED_MEMORY_ALLOCATION);
    }

    while (scanf("%10lu%30s%30s", &info->num, info->place, info->responsible) != EOF) {
        if (strlen(info->place) && strlen(info->responsible)) {  //  неправильные (неполные данные) не запишутся
            fwrite(info, sizeof(form_t), 1, database);
        }
        strcpy(info->place, "");
        strcpy(info->responsible, "");
    }

    free(info);
    return database;
}

FILE* add_to_existing_data_base(FILE *database, char filename[]) {
    database = fopen(filename, "ab");

    if (database == NULL) {
        exit(FAILED_FILE_OPENNING);
    }

    form_t* info = calloc(1, sizeof(form_t));
    if (info == NULL) {
        exit(FAILED_MEMORY_ALLOCATION);
    }
    while (scanf("%10lu%30s%30s", &info->num, info->place, info->responsible) != EOF) {
        if (strlen(info->place) && strlen(info->responsible)) {  //  неправильные (неполные данные) не запишутся
            fwrite(info, sizeof(form_t), 1, database);
        }
        strcpy(info->place, "");
        strcpy(info->responsible, "");
    }

    free(info);
    return database;
}


main_list_t* read_from_database(char filename[]) {
    FILE* database = fopen(filename, "rb");

    if (database == NULL) {
        exit(FAILED_FILE_OPENNING);
    }

    form_t* get_data = malloc(sizeof(form_t));
    if (get_data == NULL) {
        exit(FAILED_MEMORY_ALLOCATION);
    }

    fread(get_data, sizeof(form_t), 1, database);
    
    main_list_t* head = initialise_main_list(get_data);

    while (fread(get_data, sizeof(form_t), 1, database) != 0) {
        head = add_elem_to_main_structure(get_data, head);
    }

    free(get_data);
    if (fclose(database)) {
        exit(FAILED_FILE_CLOSING);
    }
    return head;
}
