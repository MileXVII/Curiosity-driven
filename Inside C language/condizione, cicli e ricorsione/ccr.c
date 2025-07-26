#include <stdio.h>

void count(int, int );

int main(void){

// IF STATEMENT

    int i = 2;
    
    if (i > 3) { // {...} is a block
        printf("i > 3\n");
    } else {
        printf("i <= 3\n");
    }

    /* IF WE EXECUTE A SINGLE STATEMENT, BLOCKS ARE NOT NEEDED

       1) if (i < 3) printf("i > 3\n");

       or

       2) if (i < 3) 
            printf("i > 3\n");

       or

       3) if (i < 3){
            printf("i > 3\n");
          }

       AND EVEN WITH ELSE WE CAN OMIT BLOCKS
       4) if (i > 3)
              printf("i > 3\n");
          else 
              printf("i <= 3\n");
    */

    // WE CAN PLACE A BLOCK ANYWHERE
    {
        int j = 5; // lexical scope inside the block
        printf("j is %d\n", j);
    }

    /* OUTSIDE THAT BLOCK THIS WON’T WORK:
        printf("j is %d\n", j);
       BECAUSE j IS LOCAL TO THE BLOCK
    */

    // ANOTHER EXAMPLE
    int x = 8;

    {
        int x = 5; // lexically scoped inside this block
        printf("\nfirst inner x is %d\n", x); // will print 5
        printf("first inner x (%zu bytes) is stored at %p\n", sizeof(x), &x);
    }

    {
        int x = 6;
        printf("\nsecond inner x is %d\n", x); // will print 6
        printf("second inner x (%zu bytes) is stored at %p\n", sizeof(x), &x);
    }

    printf("\nouter x is %d\n", x); // will print 8
    printf("outer x (%zu bytes) is stored at %p\n\n\n", sizeof(x), &x);


// GOTO: LOOP FROM 1 TO 10
    printf("\n\nGOTO loop 1–10:\n\n");
    i = 0;

again:
    printf("%d\n", i);
    i++;
    if (i < 10) goto again;

/* INFINITE LOOP PRINTING "ciao" IN BASIC STYLE:
    l10: printf("ciao\n");
    l20: goto l10;
*/


// WHILE: LOOP FROM 1 TO 10
    printf("\n\nWHILE loop 1–10:\n\n");
    i = 0;
    while(i <= 10){
        printf("%d\n", i);
        i++;
    }; // semicolon is optional


// WHILE LOOP WRITTEN USING GOTO
    printf("\n\nWHILE loop translated into GOTO:\n\n");
    i = 0;
loop:
    if (!(i <= 10)) goto next;
        printf("%d\n", i);
        i++;
        goto loop;
next:

    printf("\n\n");

// FOR LOOP EQUIVALENT TO WHILE
    printf("\n\nFOR loop equivalent to WHILE:\n\n");

    for(i = 0; i < 10; i++) {
        // if i is already declared, we could write: for(; i<10; i++)
        printf("%d\n", i);
    }

/* FOR LOOP WITH EVERYTHING OMITTED:
    i = 0;
    for(;;) { // infinite loop
        if (i > 10) break;
        printf("%d\n", i);
        i++;
    }
*/

/* COMPACT FOR LOOP IN ONE LINE:
    for (int i = 0; i < 10; i++) printf("%d\n", i);
    // → after the loop, i is out of scope
*/


/* INFINITE WHILE LOOP:

    while(1) { // In C: 1 = true, 0 = false
        ...
    }
*/


/* DO-WHILE LOOP:
    do {
        ...
    } while(condition);

    NOTE: the loop executes **at least once**, regardless of the condition.
*/


printf("\n\n");

// SWITCH STATEMENT

    i = 10;

    switch(i) {
        case 5: 
            printf("It's a five\n"); 
            break;

        case 7: 
            printf("It's a seven\n"); 
            break;

            printf("YES!! It's definitely a nice seven\n"); 
            break;

        default: 
            printf("Some other number\n"); 
            break;
    }

/* EQUIVALENT TO:

    if (i == 5) {
        ...
    } else if (i == 7) {
        ...
    } else { // default
        ...
    }

IMPORTANT DIFFERENCE: you can't declare variables inside a switch 
unless you wrap them inside a block.
*/



printf("\n\n");
// RECURSION
    printf("\n\nCount from 1 to 10 using recursive function count:\n\n");
    count(0, 10);


    return 0;
}


void count(int start, int end) {
    if(start > end) return;
    printf("%d\n", start);
    count(start + 1, end);

    /* EVEN IF A FUNCTION CALLS ITSELF,
       NEW VARIABLES (start, end) ARE CREATED EACH TIME.
       You can verify this by printing their memory addresses:
       printf("%p %p", &start, &end);

       This means that even though recursion is elegant,
       it consumes more memory compared to loops.
    */

    /*
    IMPROVEMENT USING GOTO TO SAVE MEMORY:

    iterate:
        if (start > end) return;
        printf("%d\n", start);
        start = start + 1; // or simply start++;
        goto iterate;

    NOTE: this is only safe when the function is tail-recursive.
    */
}
