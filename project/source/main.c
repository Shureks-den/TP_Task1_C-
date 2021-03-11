#include "file_creation.h"
#include "form_sorter.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        puts("Wrong number of arguments");
        return -1;
    }
    FILE* database = NULL;

    if (strcmp(argv[1], "-c") == 0) {
        database = create_new_database(database, argv[2]);
    }

    if (strcmp(argv[1], "-a") == 0) {
        database = add_to_existing_data_base(database, argv[2]);
    }

    if (strcmp(argv[1], "-r") == 0) {
        main_list_t* structure = NULL;
        structure = read_from_database(argv[2]);
        print_everything(structure);
        clear_everything(structure);
    }

    if (database != NULL) {
        fclose(database);
    }

    return 0;
}