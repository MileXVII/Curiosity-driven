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
    struct node *prev;
    void *value;
    int sentinel;
}node_s;

node_s* node_sentinel(void);
node_s* node_new(void *val);
void node_enqueue(node_s *h, node_s *n);
node_s *node_dequeue(node_s *h);
void list_free_int(node_s *h);
void print_list_int(node_s *h);

int main(void) {

    node_s *h = node_sentinel();
    print_list_int(h);
    printf("\n");

    for(int i = 1; i <= 5; i++) {
        int *val = malloc(sizeof(int));
        if(!val) error("Malloc failed");
        *val = i * 10;
        node_enqueue(h, node_new(val));
        print_list_int(h);
    }
    printf("\n");

    for(int i = 0; i < 3; i++) {
        node_s *dequeued = node_dequeue(h);
        if(!dequeued->sentinel) {
            printf("Removed: %d\n", *(int*)dequeued->value);
            free(dequeued->value);
            free(dequeued);
            print_list_int(h);
        } else {
            printf("Empty List!\n");
            break;
        }
    }
    printf("\n");

    int *val100 = malloc(sizeof(int));
    int *val200 = malloc(sizeof(int));
    if(!val100 || !val200) error("Malloc failed");
    *val100 = 100;
    *val200 = 200;
    
    node_enqueue(h, node_new(val100));
    node_enqueue(h, node_new(val200));
    print_list_int(h);
    printf("\n");

    node_s *dequeued;
    while(!(dequeued = node_dequeue(h))->sentinel) {
        printf("Removed: %d\n", *(int*)dequeued->value);
        free(dequeued->value);
        free(dequeued);
        print_list_int(h);
    }
    printf("\n");

    int *val999 = malloc(sizeof(int));
    if(!val999) error("Malloc failed");
    *val999 = 999;
    node_enqueue(h, node_new(val999));
    print_list_int(h);
    printf("\n");

    list_free_int(h);
    free(h);
    return 0;
}

node_s* node_new(void *val) {
    node_s *n = calloc(1, sizeof(node_s));
    if(!n) error("Calloc failed");
    n->value = val;
    n->sentinel = 0;
    n->next = n->prev = n;
    return n;
}

node_s* node_sentinel(void) {
    node_s *n = node_new(NULL);
    n->sentinel = 1;
    return n;
}

void node_add_after(node_s *h, node_s *n) {
    n->prev = h;
    n->next = h->next;
    h->next->prev = n;
    h->next = n;
}

void node_enqueue(node_s *h, node_s *n) {
    node_add_after(h, n);
}

node_s *node_dequeue(node_s *h) {
    node_s *p = h->prev;
    if(p == h) return h;

    p->prev->next = h;
    h->prev = p->prev;
    p->next = p->prev = p;
    return p;
}

void print_list_int(node_s *h) {
    node_s *c = h->next;
    while(c != h) {
        printf("[%d]-->", *(int*)c->value);
        c = c->next;
    }
    printf("NULL\n");
}

void list_free_int(node_s *h) {
    node_s *it;
    while(!(it = node_dequeue(h))->sentinel) {
        printf("Freeing node with value: %d\n", *(int*)it->value);
        free(it->value);
        free(it);
    }
}