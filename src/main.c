#include "../include/form/form_sorter.h"
#include "../include/form/file_creation.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        puts("Wrong number of arguments");
        return WRONG_NUM_OF_ARG;
    }

    int error_code = NO_ERROR;

    if (strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "-c") == 0) {
        if (argc < 4) {
            puts("Wrong number of arguments to write to a file");
            return WRONG_NUM_OF_ARG;
        }
        int num = atoi(argv[3]);
        error_code = write_to_database(argv[2], argv[1], num);
        if (error_code) {
            return error_code;
        }
    }

    if (strcmp(argv[1], "-r") == 0) {
        main_list_t* structure = NULL;
        structure = read_from_database(argv[2]);
        error_code = print_form_structure(structure);
        if (error_code) {
            return error_code;
        }
        error_code = clear_everything(structure);
        if (error_code) {
            return error_code;
        }
    }

    return error_code;
}
