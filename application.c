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

    while(temp->next != NULL){
        data = temp->data;
        print_bankaccount_details(data);
        temp = temp->next;
    }
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

    dll_t *dll = get_new_dll();

    add_data_to_dll(dll, account1);
    add_data_to_dll(dll, account2);
    add_data_to_dll(dll, account3);

    print_bankaccount_db(dll);
    
    return 0;
};