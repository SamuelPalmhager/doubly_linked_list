#include "dll.h"
#include "memory.h"
#include <stdlib.h>
#include <stdio.h>


int main(){

    dll_t *dll = get_new_dll();

    dll_node_t *node1 = calloc(1, sizeof(dll_node_t));

    node1->data = 10;
    node1->next = nullptr;
    node1->prev = nullptr;

    dll_node_t *node2 = new dll_node_t;
    node2->data = 20;
    dll_node_t *node3 = new dll_node_t;
    node3->data = 30;

    add_data_to_dll(dll, node1);
    add_data_to_dll(dll, node2);
    add_data_to_dll(dll, node3);

    print_dll(dll);

    delete node1;
    delete node2;
    delete node3;

    return 0;
};