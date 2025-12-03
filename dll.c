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

void register_key_match_callback(dll_t* dll, int (*key_match)(void*, void*)){
    dll->key_match = key_match;
};

void* dll_search_by_key(dll_t *dll, void* key){

    if(!dll || !dll->head) return -1;

    dll_node_t *head = dll->head;

    while(head){
        if(dll->key_match(head->data, key) == 0){
            return head->data;
        }
        head = head->next;
    }
    return NULL;
}

void register_comp_callback(dll_t* dll, int (*comp_match)(void*, void*)){
    dll->comp_match = comp_match;
};

int dll_priority_insert_data(dll_t *dll, void* app_data){

    if(!dll || !dll->head) return -1;

    if(!dll->head){ // No head in dll
        add_data_to_dll(dll, app_data);
        return 0;
    }
    dll_node_t *node = calloc(1, sizeof(dll_node_t));
    node->data = app_data;
    node->next = NULL;
    node->prev = NULL;


    //Only one node in dll
    if(dll->head && !dll->head->next){
        if(dll->comp_match(dll->head->data, app_data) == -1){ //The balance of head is bigger than app_data 
            dll->head->next = node;
            node->prev = dll->head;
        } else{
            //Replace head with new node
            dll->head->prev = node;
            node->next = dll->head;
            dll->head = node;
        }
        return 0;
    }       
    if(dll->comp_match(app_data, dll->head->data) == -1){ //More than one node in dll and dll->head->data > app_data
        dll->head->prev = node;
        node->next = dll->head;
        dll->head = node;
    };

    dll_node_t *prev = NULL, *curr = NULL;

    curr = dll->head;
    while(curr){
        if(dll->comp_match(app_data, curr->data) != -1){ //if curr->data > app_data, then traverse further
            prev = curr;
            curr = curr->next;
            continue;
        }

        prev->next = node;
        node->prev = prev;
        node->next = curr;
        curr->prev = node;
        return 0;

    }

    prev->next = node;
    node->prev = prev;
    return 0;
};
