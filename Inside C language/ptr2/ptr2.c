#include <stdio.h>

int main(void) {
    char str[] = "aabb"; //questi caratteri corrispondono a dei numeri in ascii
    short *s = (short*)str;

    /*Se acceddo all'indirizzo di memoria
    1) attraverso str  ci accedo prendendo  (str[0] = "a", str[1] = "a", ...)
    2) attraverso *s prendo interno a 16bit (s[0] = "aa", s[1] = "bb")
    */

    printf("%d %d \n", s[0], s[1]); /*stampa 0x6161 = 24929 e 0x6262 = 25186*/

    /*se inizializzo str[] = {1, 1, 2, 2}; funziona pure ed i byte varranno effettivamente: 1 1 2 2*/

    char str1[] = "Hello0000123";
    char *p = str1;

    while(*p) { //while *p not equals 0
        putchar(*p); //stampa la stringa perche' lo stampo come carattere
        p++;
    }
    printf("\n");

    //se invece
    char *p2 = str1;
    while(*p2) { //while *p not equals 0
        printf("%d ", *p2); //stampa l'intero di quel char rappresentato
        p2++;
    }

    /*Se invece str1 fosse: char str1[] = "Hello\0000000123";
    con \000 lo 0 in ottale, si fermerebbe quando lo trova.
    */    

    printf("\n");


    //*possiamo anche scrivere:
    char str2[] = "\017Hello\0000000123"; //\017 indica la lunghezza prefissata della stringa (max 255 byte essendo che abbiamo usato un solo byte)
    char *p3 = str2;
    printf("My string len is %d\n", p3[0]);
    int len = *p3++;
    for(int j = 0; j < len; j++) {
        putchar(p3[j]);
    }
    printf("\n");

    return 0;
}