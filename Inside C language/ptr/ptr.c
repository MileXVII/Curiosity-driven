#include <stdio.h>

void incr(int *p) {
    printf("before incrementing: %d\n", *p);
    *p = *p + 1; // the integer stored at address p becomes itself + 1
    // p[0] = p[0] + 1;
}

void printstr(char*);

int main(void){
    int x = 5; // integer variable stored somewhere in memory
    int *y = NULL; /* pointer to an integer; NULL is equivalent to 0 for pointers.
    y doesn't store an actual integer but holds the memory address of one.
    */
    y = &x; /* y, which can store the address of an integer, is assigned the address of x.
    Note: the '&' operator before a variable gives its memory address, not its value.
    */
    printf("x is stored at address: %p and has value %d\n", y, x); // you could also write '&x' instead of 'y'
    
    /* y = 10; this would make y point to memory address 10 */
    /* *y = 10; writes 10 into the memory location that y points to.
       Alternatively: y[0] = 10;
    */

    incr(y);
    incr(&x); // same thing

    /*
    Even though 'x' is a local variable and normally only accessible in main,
    by passing its memory address we can access it outside of main.
    */

    printf("x is now %d\n", x);

    int **z = &y; // pointer to a pointer to an integer
    printf("y is stored at address: %p\n", z);

    printf("\n\n");
    printf("x size: %d bytes,\ny size: %d bytes,\nz size: %d bytes\n",
           (int)sizeof(x), (int)sizeof(y), (int)sizeof(z));
    // All pointers typically have the same size (usually 8 bytes on 64-bit systems)
    printf("\n\n");

    char mystr[] = "AABBCCDDEEFF";
    printf("%s\n", mystr);
    char *p = mystr;
    printf("at: %p we can see: '%s'\n", mystr, mystr);
    printf("%c%c\n\n", p[0], p[1]); // prints: AA
    // printf("%c%c\n", *p, *(p+1));

    printf("Initially, p is %p\n", p);
    while(*p != 0) {
        putchar(*p); // p[0]
        p++;
    }
    printf("\n");

    /*
    while(*p != E) {
        putchar(p[1]); // would always print the next character
        p++;
    }
    */

    printf("Afterwards, p is %p\n", p);

    char *ptr = mystr;

    printstr(ptr);
    printstr(mystr);
    printstr(mystr + 3);

    printf("\n\n");

    /*
    short *p1 = (short*)mystr;
    p1++;
    printf("%d\n", *p1);

    NOTE:
    WHEN YOU INCREMENT ANY POINTER BY 1,
    THAT 1 IS ACTUALLY MULTIPLIED BY THE SIZE OF THE POINTER'S BASE TYPE.
    So in this case, if we're on the first 'A' and increment p by 4 (p += 4),
    we won’t reach the second 'B'. Since short is 2 bytes,
    we’ll end up at 'E'.
    The same applies to p[4]
    */
    return 0;
}

// STRING PRINT FUNCTION
void printstr(char* p) {
    while(*p != 0) {
        putchar(p[0]); // *p
        p++;
    }
    printf("\n");
}
