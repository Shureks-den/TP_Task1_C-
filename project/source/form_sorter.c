#include "form_sorter.h"
#include <stdbool.h>

main_list_t* add_elem_to_main_structure(form_t* element, main_list_t* head) {
    if (element == NULL) {
        return NULL;
    }
    main_list_t* current = head;
    main_list_t* pre_current = head;

    while (current != NULL) {  // поиск по всем существующим узлам
        if (strcmp(current->head->data.place, element->place) == 0 &&
            strcmp(current->head->data.responsible, element->responsible) == 0) {
            current->head = insert_form(current->head, element);
            return head;
        }
        pre_current = current;
        current = current->next_list;
    }

    current =  initialise_main_list(element);  // вставка нового узла
    pre_current->next_list = current;
    return head;
}

main_list_t* initialise_main_list(form_t* element) {
    if (element == NULL) {
        return NULL;
    }

    main_list_t* current = malloc(sizeof(main_list_t));
    if (current == NULL) {
        return NULL;
    }
    current->next_list = NULL;
    current->head = NULL;
    current->head = malloc(sizeof(form_list_t));

    if (current->head == NULL) {
        free(current);
        return NULL;
    }
    current->head->next = NULL;

    current->head->data.num = element->num;
    snprintf(current->head->data.place,  sizeof(element->place), "%s", element->place);
    snprintf(current->head->data.responsible, sizeof(element->responsible), "%s", element->responsible);

    return current;
}

form_list_t* insert_form(form_list_t* head, form_t* element) {
    form_list_t* current = head;
    form_list_t* pre_current = current;

    if (head->data.num > element->num) {  // вставка в качестве первого
        head = copy_data(NULL, head, element);
        return head;
    }

    while (current != NULL) {
        if (current->data.num > element->num) {  // вставка в списке
            copy_data(pre_current, current, element);
            return head;
        }
        pre_current = current;
        current = current->next;
    }
    copy_data(pre_current, NULL, element);
    return head;
}

form_list_t* copy_data(form_list_t* pre_current, form_list_t* current, form_t* element) {  // вроде работает
    form_list_t* new_elem = malloc(sizeof(form_list_t));

    if (pre_current != NULL) {
        pre_current->next = new_elem;
    }
    new_elem->next = current;

    new_elem->data.num = element->num;
    snprintf(new_elem->data.place, sizeof(element->place), "%s", element->place);
    snprintf(new_elem->data.responsible, sizeof(element->responsible), "%s", element->responsible);
    return new_elem;
}

int print_everything(main_list_t* head) {
    main_list_t* q = head;
    printf("----------------------\n\n");
    while (q != NULL) {
        form_list_t* p = q->head;
        while (p != NULL) {
            if (print_info(*p) < 0) {
                return -1;
            }
            p = p->next;
        }
        q = q->next_list;
        printf("----------------------\n");
    }
    return NO_ERROR;
}

int print_info(form_list_t get_data) {
    return printf("%lu\n%s\n%s\n\n", get_data.data.num, get_data.data.place, get_data.data.responsible);
}

int clear_everything(main_list_t* head) {
    main_list_t* clean_struct = head;

    while (head != NULL) {
        form_list_t* clean_list = head->head;
        while (head->head != NULL) {
            head->head = head->head->next;
            free(clean_list);
            clean_list = head->head;
        }

        head = head->next_list;
        free(clean_struct);
        clean_struct = head;
    }
    return NO_ERROR;
}
