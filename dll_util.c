#include "dll.h"

int remove_data_from_dll(dll_t *dll, void* app_data){
    
    if(!dll || !dll->head) return -1;

     dll_node_t *temp = dll->head;

     while(temp){
        
        if(temp->data == app_data){

                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                free(temp);
                return 0;
        }

        temp = temp->next;
     }
    printf("Node to delete not found!\n");
    return -1;
};

int is_dll_empty(dll_t *dll){

    if(!dll->head) return -1;
    return 0;

};

void drain_dll(dll_t *dll){

    dll_node_t *temp = dll->head;

    while(temp){
        temp->data = NULL;
        temp = temp->next;
    };

};