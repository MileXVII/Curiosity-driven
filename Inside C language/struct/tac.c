#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*tac command*/

struct line {
    char *s;
    struct line *next;
};

void error(char *err) {
    fprintf(stderr, "[ERROR]: %s!\n", err);
    exit(1);
}

int main(int argc, char **argv) {

    if(argc != 2) {
        printf("Missing file name\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("File does not exist\n");
        return 1;
    } 

    char buf[1024]; //potential overflow 
    struct line *head = NULL;

    while (fgets(buf, sizeof(buf), fp) != NULL) { 
        struct line *l = malloc(sizeof(struct line));
        if(l == NULL) error("Malloc Function failed");
        size_t linelen = strlen(buf);
        l->s = malloc(linelen + 1); 
        if(l->s == NULL) error("Malloc Function failed");
        for(size_t j = 0; j <= linelen; j++) {
            l->s[j] = buf[j]; //this for cycle can be replaced with: "strcpy(l->s, buf);"

        }
        l->next = head;
        head = l;
    }

    fclose(fp);

    while(head != NULL) {
        printf("%s", head->s);
        struct line *temp = head;
        head = head->next;
        free(temp->s);
        free(temp);
    }

    return 0;
}
