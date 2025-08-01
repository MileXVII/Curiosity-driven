#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    return a-b;
}

int mux(int a, int b) {
    return a*b;
}

int division(int a, int b) {
    return b!= 0 ? a / b : 0;
}

int main(void) {

    int (*operation)(int, int);

    char operator = '+';

    if(operator == '+') {
        operation = sum;
    } else if (operator == '-') {
        operation = sub;
    }

    int result = operation(10, 5);
    printf("result: %d\n", result);

    //or...

    int (*other_operation[4])(int, int) = {sum, sub, mux, division};

    int choice = 2; //select mux;
    result = other_operation[choice](10, 5);

    printf("result: %d\n", result);
}