#ifndef _DOUBLY_LINKED_LIST_
#define _DOUBLY_LINKED_LIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct dll_node_{
    void* data;
    struct dll_node_ *next;
    struct dll_node_ *prev;
}dll_node_t;

typedef struct dll_{
    dll_node_t *head;
}dll_t;


/**
 * Function to get a new dll;
 * @return dll_t*, pointer to beginning of new dll.
 */

dll_t* get_new_dll();

/**
 * Function to add new data to dll, will add in the beginning or end of dll
 * @param dll pointer to dll we will add data to. @param app_data pointer to new node which should be added
 * @return will return 0 if successful, or 1 if not successful. 
 */

int add_data_to_dll(dll_t* dll, void* app_data);


/**
 * Function to print dll
 */
void print_dll(dll_t* dll);
#endif //_DOUBLY_LINKED_LIST_