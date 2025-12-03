#include "dll.h"
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bankaccount_{

    double balance;
    int account_id;
    char owner[32];

}bankaccount_t;

static void print_bankaccount_details(bankaccount_t *account){

    printf("Balance is: %.2f \n", account->balance);
    printf("Account ID is: %d \n", account->account_id);
    printf("Owner is: %s \n", account->owner);

};

static void print_bankaccount_db(dll_t* account_db){

    if(!account_db || !account_db->head) return;

    dll_node_t *temp = account_db->head;
    bankaccount_t *data = NULL;

    while(temp){
        data = temp->data;
        print_bankaccount_details(data);
        temp = temp->next;
    }
};

static int match_bankaccount_key(void* data, void* key){

    bankaccount_t *acc = (bankaccount_t*)data;
    unsigned int rollno = (unsigned int)key;

    if(acc->account_id == key) return 0;

    return -1;
};

static int bankaccount_comparison_fn(void* app_data1, void* app_data2){

    bankaccount_t *acc1 = (bankaccount_t*) app_data1;
    bankaccount_t *acc2 = (bankaccount_t*) app_data2;

    if(acc1->balance == acc2->balance) return 0;
    if(acc1->balance > acc2->balance){
        return 1;
    }else 
    return -1;

};

int main(int argc, char** argv){

    bankaccount_t *account1 = calloc(1, sizeof(bankaccount_t));
    account1->balance = 100.1234;
    account1->account_id = 1;
    strncpy(account1->owner, "Samuel", strlen("Samuel"));
    printf("Created account1 with %s as name \n", account1->owner);

    bankaccount_t *account2 = calloc(1, sizeof(bankaccount_t));
    account2->balance = 200.1234;
    account2->account_id = 2;
    strncpy(account2->owner, "Simon", strlen("Simon"));
    printf("Created account3 with %s as name \n", account2->owner);


    bankaccount_t *account3 = calloc(1, sizeof(bankaccount_t));
    account3->balance = 300.1234;
    account3->account_id = 3;
    strncpy(account3->owner, "Elias", strlen("Elias"));
    printf("Created account3 with %s as name \n", account3->owner);

    bankaccount_t *account4 = calloc(1, sizeof(bankaccount_t));
    account4->balance = 400.1234;
    account4->account_id = 4;
    strncpy(account4->owner, "Elli", strlen("Elli"));
    printf("Created account4 with %s as name \n", account4->owner);

    bankaccount_t *account5 = calloc(1, sizeof(bankaccount_t));
    account5->balance = 450.1234;
    account5->account_id = 5;
    strncpy(account5->owner, "Bengt", strlen("Bengt"));
    printf("Created account5 with %s as name \n", account5->owner);

    dll_t *dll = get_new_dll();

    register_key_match_callback(dll, match_bankaccount_key);
    register_comp_callback(dll, bankaccount_comparison_fn);

    add_data_to_dll(dll, account1);
    add_data_to_dll(dll, account2);
    add_data_to_dll(dll, account3);

    print_bankaccount_db(dll);

    printf("Is DLL empty? %d \n", is_dll_empty(dll));

    remove_data_from_dll(dll, account2);
    remove_data_from_dll(dll, account4);
    printf("Searching for %s, search was %s successful \n", account4->owner, dll_search_by_key(dll, (void*)(4)) == 0 ? "" : "not");

    dll_priority_insert_data(dll, account5);

    print_bankaccount_db(dll);

    drain_dll(dll);

    //print_dll(dll);

    return 0;
};