#include "../include/form/file_creation.h"
#include "../include/form/form_sorter.h"

int write_to_database(const char filename[], const char action[], const size_t num) {
    FILE* database = NULL;
    if (strcmp(action, "-c") == 0) {
        database = fopen(filename, "wb");
    }

    if (strcmp(action, "-a") == 0) {
        database = fopen(filename, "ab");
    }

    if (database == NULL) {
        puts("File not found");
        return(FAILED_FILE_OPENNING);
    }

    form_t* info = calloc(1, sizeof(form_t));
    if (info == NULL) {
        puts("Memory error");
        if (fclose(database)) {
            return FAILED_FILE_CLOSING;
        }
        return(FAILED_MEMORY_ALLOCATION);
    }

    size_t i = 0;
    while (i < num) {
        if (fscanf(stdin, "%10lu%30s%30s", &info->num, info->place, info->responsible) < 0) {
            puts("Error getting full data");
            free(info);
            if (fclose(database)) {
                return FAILED_FILE_CLOSING;
            }
            return(SCANF_ERROR);
        }
        if (strlen(info->place) && strlen(info->responsible)) {  //  неправильные (неполные данные) не запишутся
            fwrite(info, sizeof(form_t), 1, database);
        } else {
            puts("Some data was incomplete and didn't write to a file");
        }
        snprintf(info->place, sizeof(info->place), "%s", "");
        snprintf(info->responsible, sizeof(info->place), "%s", "");
        i++;
    }

    free(info);
    if (fclose(database)) {
        return FAILED_FILE_CLOSING;
    }
    return NO_ERROR;
}


main_list_t* read_from_database(const char filename[]) {
    FILE* database = NULL;
    database = fopen(filename, "rb");

    if (database == NULL) {
        puts("File not found");
        return NULL;
    }

    form_t* get_data = malloc(sizeof(form_t));
    if (get_data == NULL) {
        puts("Memory error");
        fclose(database);
        return NULL;
    }

    if (fread(get_data, sizeof(form_t), 1, database) == 0) {
        puts("FILE IS EMPTY");
        fclose(database);
        return NULL;
    }

    main_list_t* head = NULL;
    head = initialise_main_list(get_data);

    while (fread(get_data, sizeof(form_t), 1, database) != 0) {
        head = add_elem_to_main_structure(get_data, head);
    }

    free(get_data);
    if (fclose(database)) {
        return NULL;
    }
    return head;
}


