#include <stdio.h>

// Function to sum two integers.
// We can also write int sum(int, int)
int sum(int a, int b){
    return a + b; // Returns the integer sum of a and b. N.B. the return type must match the function type. //a and b are parameters

    /*
    return accepts expressions: so also
    if(...){ } or while(...) { } etc.
    */

    /*WE CAN ALSO WRITE:
    int c; //c is a local variable.
    c = a + b;
    return c;
    */
}

// SECOND FUNCTION!!

int x = 0; // global variable, it keeps its state between calls

void incr(void){
    /*We could replace the global variable by defining it directly in the incr function like this:
    static int x = 0; it also keeps its state.

    N.B. in that case we wouldn't be able to access 'x' in main anymore because it's no longer global (it's scoped to the function),
    even if the function keeps working the same.
    */

    x = x + 1;
    printf("%d\n", x);
}

/* FUNCTION PROTOTYPE TO CALL A FUNCTION DECLARED BELOW main
int sum(int a, int b); 
or..
int sum(int, int);
*/

int main(){
    puts("Hello World!");

    printf("%d\n", sum(10, 20)); //calling the sum function inside our program //10 and 20 are arguments

    /*WE CAN ALSO ASSIGN THE RETURNED VALUE TO A VARIABLE
    int z = sum(30, 20); or int z = sum(a, b) with a, b being previously initialized variables
    // z is a local variable.
    */

    incr(); // prints 1
    incr(); // prints 2
    incr(); // prints 3
    incr(); // prints 4

    int a = 10;
    double y = 1.7532;

    printf("%d %.4f\n", a, y); //%d for integers, %f or %lf for double values.  //printf("%x, %.4f", a, y) prints "a, 1.7532", printf("%X, %.4f", a, y) prints "A, 1.7532"
    /*WARNING!! for printf it doesn’t matter whether it's float or double because float is promoted to double by default (default argument promotion),
    but in scanf, %f stores a float while %lf stores a double.*/

    return 0; // as explained in the Hello World! file, 0 is the return value of the special main function.
}

/*WE CAN ALSO DECLARE THE FUNCTION BELOW AND CALL IT ABOVE TWICE
EXAMPLE:

int sum(int a, int b){
    return a + b;
}
*/
