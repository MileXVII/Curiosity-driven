#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void error(const char *err) {
    if(errno != 0) {
        perror(err);
    } else {
        fprintf(stderr, "[ERROR]: %s!\n", err);
    }
    exit(EXIT_FAILURE);
}

typedef struct node {
    struct node *next;
    void *value;
}node_s;

node_s *node_new(void *val);
node_s *push(node_s *h, node_s *n);
void pop(node_s **h, void (*pcr)(void*));
void print_int(void *val);
void node_free(node_s *h);
void list_print_int(node_s *h);

int main(void) {
    //testing with to integers value
    int *val1 = malloc(sizeof(int));
    if(!val1) error("Malloc failed");
    int *val2 = malloc(sizeof(int));
    if(!val2) error("Malloc failed");

    *val1 = 42;
    *val2 = 84;

    node_s *h = node_new(val1);

    h = push(h, node_new(val2));

    list_print_int(h);

    pop(&h, print_int);

    list_print_int(h);

    node_free(h);

    return 0;
}

node_s *node_new(void *val) {
    node_s *n = calloc(1, sizeof(*n));
    if(!n) error("Calloc failed");
    n->next = NULL;
    n->value = val;
    return n;
}

node_s *push(node_s *h, node_s *n) {
    n->next = h;
    return n;
}

void pop(node_s **h, void (*pcr)(void*)) {
    if(!h || !*h) return; 

    node_s *nd = *h;

    if(pcr) pcr(nd->value);

    *h = (*h)->next;
    free(nd->value);
    free(nd);
}

void print_int(void *val) {
    printf("Popped: %d\n", *(int*)val);
}

void node_free(node_s *h) {
    while(h) {
        node_s *tmp = h;
        h = h->next;
        free(tmp->value);
        free(tmp);
    }
}

void list_print_int(node_s *h) {
    if(!h) return;
    node_s *c = h;
    while(c) {
        printf("[%d]-> ", *(int*)c->value);
        c = c->next;
    }
    printf("NULL\n");
}