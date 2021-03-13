#include "../include/form/form_sorter.h"
#include "../include/form/file_creation.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return WRONG_NUM_OF_ARG;
    }

    int error_code = NO_ERROR;

    if (strcmp(argv[1], "-c") == 0) {
        int num = atoi(argv[3]);
        error_code = create_new_database(argv[2], num);
        if (!error_code) {
            return error_code; 
        }
    }

    if (strcmp(argv[1], "-a") == 0) {
        int num = atoi(argv[3]);
        error_code = add_to_existing_data_base(argv[2], num);
        if (!error_code) {
            return error_code; 
        }
    }

    if (strcmp(argv[1], "-r") == 0) {
        main_list_t* structure = NULL;
        structure = read_from_database(argv[2]);
        error_code = print_everything(structure);
        if (!error_code) {
            return error_code;
        }
        error_code = clear_everything(structure);
        if (!error_code) {
            return error_code;
        }
    }
    
    return error_code;
}
