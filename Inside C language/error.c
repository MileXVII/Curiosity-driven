#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void error(const char *err) {
    if(errno != 0) {
        perror(err);
    } else{
        fprintf(stderr, "[ERROR]: %s!\n", err);
    }
    exit(EXIT_FAILURE);
}

