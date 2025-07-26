#include <stdio.h>

int main(void) {
    char str[] = "aabb"; // these characters correspond to ASCII values
    short *s = (short*)str;

    /* If I access the memory address:
    1) through str, I access it byte-by-byte (str[0] = 'a', str[1] = 'a', ...)
    2) through *s, I access it 16 bits at a time (s[0] = 'aa', s[1] = 'bb')
    */

    printf("%d %d \n", s[0], s[1]); // prints 0x6161 = 24929 and 0x6262 = 25186

    /* If I initialize str[] = {1, 1, 2, 2}; it works as well, and the bytes will be: 1 1 2 2 */

    char str1[] = "Hello0000123";
    char *p = str1;

    while(*p) { // while *p is not zero (i.e., not null terminator)
        putchar(*p); // prints the string character by character
        p++;
    }
    printf("\n");

    // alternatively:
    char *p2 = str1;
    while(*p2) { // while *p is not zero
        printf("%d ", *p2); // prints the integer value (ASCII) of the character
        p2++;
    }

    /* If instead str1 were: char str1[] = "Hello\0000000123";
       the loop would stop at \000 since it's the null terminator (octal escape)
    */

    printf("\n");

    // we can also write:
    char str2[] = "\017Hello\0000000123"; // \017 (octal 017 = decimal 15) acts as a length prefix (max 255 bytes, since it uses one byte)
    char *p3 = str2;
    printf("My string len is %d\n", p3[0]);
    int len = *p3++;
    for(int j = 0; j < len; j++) {
        putchar(p3[j]);
    }
    printf("\n");

    return 0;
}
