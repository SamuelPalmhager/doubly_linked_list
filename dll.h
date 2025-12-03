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
    int (*key_match)(void*, void*); 
    int (*comp_match)(void*, void*);
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

/**
 * Function to remove data in a node from dll
 * @param dll pointer to dll on which to perform deletion. @param app_data the contents of the node which to remove
 * @return will return 0 if successful, or -1 if not successful. 
 */

int remove_data_from_dll(dll_t* dll, void* app_data);

/**
 * Function to check if a dll is empty
 * @param dll pointer to dll which to check if empty
 * @return will return 0 if empty, or -1 if not empty. 
 */

int is_dll_empty(dll_t* dll);

/**
 * Function to delete all nodes from a dll, but wont free the appln data
 * @param dll pointer to dll which to drain
 */

void drain_dll(dll_t* dll);


/**
* Function to register a callback
* @param dll dll to search through, @param int method signature for the search function to register
*/

void register_key_match_callback(dll_t *dll, int (*key_match)(void*, void*));


/**
* Function to search the dll and return 
*/

void* dll_search_by_key(dll_t *dll, void *key);


/**
* Function to register comparison method callback 
* @param dll dll to register the callback on, @param int method signature for the comparison function to register 
*/

void register_comp_callback(dll_t *dll, int (*comp_match)(void*, void*));

int dll_priority_insert_data(dll_t*, void*);

#endif //_DOUBLY_LINKED_LIST_