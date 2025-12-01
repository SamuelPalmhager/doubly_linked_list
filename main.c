#include "dll.h"
#include "memory.h"
#include <stdlib.h>
#include <stdio.h>


int main(){

    dll_t *dll = get_new_dll();

    dll_node_t *node1 = calloc(1, sizeof(dll_node_t));

    node1->data = 10;
    node1->next = NULL;
    node1->prev = NULL;

    dll_node_t *node2 = calloc(1, sizeof(dll_node_t));
    node2->data = 20;
    dll_node_t *node3 = calloc(1, sizeof(dll_node_t));
    node3->data = 30;

    add_data_to_dll(dll, node1);
    add_data_to_dll(dll, node2);
    add_data_to_dll(dll, node3);

    print_dll(dll);

    free(node1);
    free(node2);
    free(node3);

    return 0;
};