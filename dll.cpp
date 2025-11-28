#include "dll.h"
#include <stdio.h>
#include <memory>
#include <iostream>

dll_t* get_new_dll(){

    dll_t *dll = new dll_t;

    dll->head = new dll_node_t;
    dll->head->data = 1;
    dll->head->next = nullptr;
    dll->head->prev = nullptr;

    return dll;
};

int add_data_to_dll(dll_t* dll, void* app_data){

    //We need to check if we should add in the beginning or end of the list
    
    if(!dll || !dll->head) return 1;

      //Assign to heads next node

        dll_node_t *new_node = (dll_node_t*)app_data;
        new_node->next = nullptr;
        new_node->prev = nullptr;


    if(dll->head->next == nullptr){

        dll->head->next = new_node;
        new_node->next = nullptr; //Maybe redundant
        new_node->prev = dll->head;

        std::cout << "Added to start of dll" << std::endl;

        return 0;

    }

        dll_node_t *temp = dll->head;
        int i {0};

        while(temp->next != nullptr){
            std::cout << "Stepping in " << i << std::endl;
            temp = temp->next;
        }

        //Assume we have reached end of dll.

        temp->next = new_node;
        new_node->next = nullptr; //Maybe redundant
        new_node->prev = temp;
        return 0;

};

void print_dll(dll_t* dll){

    if(!dll || !dll->head) return;

    dll_node_t *temp {dll->head->next};
    int i {0};

    while(temp != nullptr){
        std::cout << "Data for node: " << i << " is " << (int)(temp->data) << std::endl;
        temp = temp->next;
        i++;
    }
    std::cout << "Reached end of dll" << std::endl;

}