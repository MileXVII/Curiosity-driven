#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

typedef struct Node{
    int value;
    struct Node *next;
}node;

void error(const char *err) {
    if(errno != 0) {
        perror(err);
    } else {
        fprintf(stderr, "[ERROR]: %s!\n", err);
    }
    exit(EXIT_FAILURE); 
}

void printList(const node *head);
void InsertNode(int value, node **head);
void deleteNode(int value, node **head);
void freeList(node **head);

int main(void) {
    node *head = NULL;
    int inputData[5] = {10, 12, 2, 34, 1};

    for(unsigned short i = 0; i < 5; i++) {
        printf("\n Trying to add data: [%d]", inputData[i]);
        InsertNode(inputData[i], &head);
    }

    putchar('\n');

    printList(head);

    int deleteData[3] = {7, 10, 34};

    for(unsigned short i = 0; i < 3; i++) {
        printf("\n Trying to delete data: [%d]", deleteData[i]);
        deleteNode(deleteData[i], &head); 
    }

    putchar('\n');

    printList(head);

    printf("\n Trying to free memory...\n");
    freeList(&head);

    return 0;
}

void printList(const node *head) {
    const node *ptr = head;

    printf("\n === LIST ===\n");
    while(ptr != NULL){
        printf(" [%d] ", ptr->value);
        ptr = ptr->next;
    }

    printf("\n === END LIST ===\n");
}

int datacmp(const int value1, const int value2) {
    if(value1 > value2)
        return 1;
    else if(value1 < value2)
        return -1;
    return 0;
}

void InsertNode(int value, node **head) {
    node* new = malloc(sizeof(*new));
    if(new == NULL) error("Malloc function failed");
    
    new->next = NULL;
    new->value = value;

    if(*head == NULL) {
        *head = new;
        return;
    }

    node *current = *head, *previous = NULL;
    while(current != NULL && datacmp(current->value, new->value) < 0){
        previous = current;
        current = current->next;
    }

    if(previous != NULL) {
        previous->next = new;
    } else {
        *head = new;
    }

    if(current != NULL) new->next = current;
}

void deleteNode(int value, node **head) {
    if(*head == NULL) return;  

    node *current = *head, *previous = NULL;
    
    while(current != NULL && datacmp(current->value, value) != 0){
        previous = current;
        current = current->next;
    }

    if(current != NULL) { 
        if(previous) {
            previous->next = current->next;
        } else {
            *head = current->next;
        }
        free(current); 
    }
}

void freeList(node **head) {
    node *current = *head;
    node *next;
    
    while(current != NULL) {
        next = current->next;  
        free(current);         
        current = next;        
    }
    
    *head = NULL; 
}