/* NOTE:
IT IS IMPORTANT TO REVIEW EACH EXERCISE FROM FIRST TO LAST. MOST OF THE WORK AND SKILLS MUST BE ACQUIRED INDEPENDENTLY.
*/

#include <stdio.h> // file.h 1) 'h' stands for header 2) header files are included to use commands not originally part of C (like printf())
// N.B. we can also write #include "file.c"

/* N.B. in this specific program we could omit <stdio.h> and instead just declare the prototype of the printf function:
int printf(const char * restrict format, ...);
The prototype can be obtained from the WSL command line with:
man 3 printf
This will fetch the 'manual' (on page 3—though not always!) for the printf() function.
N.B. 'man' is not available in PowerShell.
*/

int main() { // int main = function of type int expecting an int return value // int main(){} = int main(void){} with an implied void parameter

    printf("Hello World! \n"); // puts("x"); = printf("x\n"); (more performant if just printing a word)

    return 0; // int return for main
    /* WARNING!!
    In modern C compilers, omitting return 0 does nothing, but it is good practice to include it. In C++, it causes an error.
    You could write: void main() { }.
    The return 0 signals to the OS whether the program exited successfully.
    The Unix convention is: return 0 = success, return 1, 2, 3, etc. = various failure types.
    */

    /*
    To print the return value (e.g. "return 0") after executing the program with: "./out", type: "echo $?" — in this case it will print "0", or use: "./out; echo $?".

    You can also write: "./out && ls" — if it returns 0, ls will execute; otherwise, it won’t. Try it yourself to observe the difference in output.
    This is useful if you want to run multiple programs sequentially using "&&" — if one fails, the chain stops.

    To enter the calculator mode of the terminal, type: 'bc'. To exit, type 'quit'.
    */
}

/* FILE EXAMPLE — file.c
In 'file.c' you'd only have = printf("Hello World! \n");

int main(){
    #include "file.c"
    return 0;
}
*/

/* HOW TO RUN THE PROGRAM (IN VS CODE):
PowerShell:
    1) cd \Path\ (e.g. cd C:\Users\micha\OneDrive\Desktop\C)
    2) gcc -Wall -O2 file_name.c -o output_name (creates a .exe)
    3) .\output_name

WSL:
Note: You probably won’t have gcc installed. First update packages with: 'sudo apt update', then install gcc with: 'sudo apt install gcc'
    1) cd /Path/ (e.g. cd /mnt/c/Users/micha/OneDrive/Desktop/C)
    2) gcc -Wall -O2 file_name.c -o output_name (creates a file with no extension, executable only from command line)
    3) ./output_name

Explanation of the '-':
    1) -Wall & -W (not shown) — display all common warnings
    2) -O2 — runs with optimization level 2; allows the compiler to recognize and optimize inefficient code
       N.B. Improvements can be seen by generating an Assembly file using the '-S' option
    3) -o output_name — specifies the name of the generated executable file
*/
