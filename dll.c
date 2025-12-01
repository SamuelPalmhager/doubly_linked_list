#include "dll.h"
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

dll_t* get_new_dll(){

    dll_t *dll = calloc(1, sizeof(dll_t));
    dll->head = NULL;
    return dll;

};

int add_data_to_dll(dll_t* dll, void* app_data){

    //We need to check if we should add in the beginning or end of the list

        dll_node_t *new_node = calloc(1, sizeof(dll_node_t));
        new_node->next = NULL;
        new_node->prev = NULL;


    if(!dll->head){
        dll->head = new_node;
        dll->head->data = app_data;
        dll->head->next = NULL; //Maybe redundant
        dll->head->prev = NULL;
        return 0;

    }

        dll_node_t *temp = calloc(1, sizeof(dll_node_t));
        temp = dll->head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        //Assume we have reached end of dll.

        temp->next = new_node;
        new_node->data = app_data;
        new_node->next = NULL; //Maybe redundant
        new_node->prev = temp;

        return 0;

};

void print_dll(dll_t* dll){

    if(!dll || !dll->head) return;

    dll_node_t *temp = dll->head->next;
    int i = 0;

    while(temp != NULL){
        printf("Data for node: %d, is %d \n", i, (int)(temp->data));
        temp = temp->next;
        i++;
    }
    printf("Reached end of dll \n");

}