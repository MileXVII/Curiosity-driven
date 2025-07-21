#include <stdio.h>
#include <math.h> //per pow();
#include <limits.h> //INT_MIN, INT_MAX
#include <stdint.h> //possiamo specificare la grandezza che vogliamo

int main(){
    int x;
    printf("La variabile x e' lunga: %d bytes\n", (int)sizeof(x)); //casting int (stampa 4) 
    //ESSENDO X UNA VARIABILE INT: sizeof(x) sara' uguale a sizeof(int)
    //N.B. la chiamata sizeof non accade a runtime ma a momento della compilazione

    // printf("La variabile x e' lunga: %lu bytes\n", sizeof(x)); //senza casting (stampa 4)
    printf("La variabile x e' lunga: %.0f\n", pow(2, 32)); //equivalente di 4 bytes

    //numero massimo e numero minimo rappresentabile del tipo int
    printf("int min: %d, int max: %d\n", INT_MIN, INT_MAX);

    /*
    char c = 1; //intero 8 bit, 1 byte. N.B. anche carattere
    short s = 2000; //16 bit, 2 byte.
    int x = 5; //4 bytes -> 32 bit N.B. L'int a volte e' 8 bytes quindi 64 bit, ma usualmente e' 4 -> 32
    long l = 10; //8 bytes -> 64 bit

    <stdint.h>
    - uint64_t e' un interno senza segno di 64 bit
    - int64_t
    - size_t da solo dipende dall'architettura della macchina, 32-bit = 4 -> 32, 64-bit = 8 -> 64. In particolare si referisce alla grandezza massima di qualunque 'oggetto' noi vogliamo, es: array etc,
    - intrptr_t ci assicura che al suo intero entri un indirizzo di memoria (puntatore)
    - uintptr_t N.B. gli indirizzi di memoria sono sempre positivi, ma nel caso in cui volessimo sottrarre tra loro due indirizzi potremmo generare un valore negativo.
    */

    return 0;
}