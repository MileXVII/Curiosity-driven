#include <stdio.h>
#include <math.h>     // for pow();
#include <limits.h>   // INT_MIN, INT_MAX
#include <stdint.h>   // allows specifying the exact size we want

int main(){
    int x;
    printf("Variable x is: %d bytes long\n", (int)sizeof(x)); //casting to int (prints 4)
    //SINCE X IS AN INT VARIABLE: sizeof(x) is equal to sizeof(int)
    //N.B. sizeof is evaluated at compile time, not at runtime

    // printf("Variable x is: %lu bytes long\n", sizeof(x)); //without casting (prints 4)
    printf("Variable x is: %.0f\n", pow(2, 32)); //equivalent to 4 bytes worth of range

    // minimum and maximum representable value for int type
    printf("int min: %d, int max: %d\n", INT_MIN, INT_MAX);

    /*
    char c = 1;       //8-bit integer, 1 byte. N.B. also used for characters
    short s = 2000;   //16-bit, 2 bytes.
    int x = 5;        //4 bytes -> 32 bits. N.B. sometimes int is 8 bytes (64 bits), but usually it's 4 -> 32
    long l = 10;      //8 bytes -> 64 bits

    <stdint.h>
    - uint64_t is a 64-bit unsigned integer
    - int64_t is a 64-bit signed integer
    - size_t depends on machine architecture: 32-bit = 4 -> 32, 64-bit = 8 -> 64. It refers to the maximum size of any "object", e.g., arrays
    - intptr_t ensures it can hold a memory address (pointer)
    - uintptr_t N.B. memory addresses are always positive, but subtracting two addresses may produce a negative result
    */

    return 0;
}
