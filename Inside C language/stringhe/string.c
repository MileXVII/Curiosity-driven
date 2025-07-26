#include <stdio.h>

int main(void){

   //char c = 10; char type integer automatically cast to int
    char c = 'p'; //char type integer
    //N.B. single quotes '' in C can hold only one character

    //the character will be expanded to a number representing its position in the ASCII standard
    printf("Hello World %d \n", c); 

    //Hello World as argument
    printf("[%s]\n", "Hello World");

    //print characters
    printf("[%c%c%c%c]\n", 65, 'x', 67, 68);
    
    //char array (string)
    char str[6] = {'h', 'e', 'l', 'l', '0', 0}; // 0 without quotes or '\0' is the null terminator
    //char str2[6] = "hell0";
    //char str2[] = "hell0"; sizeof returns size 6
    /* also possible:
    1) str[3] = 'X'; 
    2) str[3] = 58;
    3) str[3]++;
    this replaces the character at position 3 in the char array
    */
    printf("%s\n", str);
   
    //print loop
    int i = 0;
    while(str[i] != 0){
        printf("%c", str[i]);
        i++;
    }
    printf("\n");

    //back to our Hello World!
    char str2[6] = "hello"; //the program automatically adds the null terminator
    printf("Hello World: %s %s\n", str, str2);

    return 0;
}
