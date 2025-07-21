#include <stdio.h>

void incr(int *p) {
    printf("prima di incrementare: %d\n", *p);
    *p = *p + 1; //l'intero che c'e' all'indirizzo p e' uguale a se stesso + 1
    //p[0] = p[0] + 1;
}

void printstr(char*);

int main(void){
    int x = 5; //variabile intera memorizzata da qualche parte in memoria
    int *y = NULL; /*puntatore di tipo intero, NULL e' uguale allo 0 per i puntatori
    y non e' grande quanto un itero, ma contiene e punta un indirizzo di memoria di un intero.
    */
    y = &x; /*y, che puo' registrare indirizzi di memoria di tipo intero, e' uguale all'indirizzo di memoria in cui x e' registrato
    N.B. l'operatore '&' prima di una variabile dice che non vogliamo il suo contenuto ma il suo indirizzo di memoria
    */   
    printf("x e' memorizzato nell'indirizzo: %p e vale %d\n", y, x); //in questo caso possiamo anche sostituire 'y' con '&x'
    /* y = 10; in questo caso y punta all'indirizzo di memoria 10*/
    /* *y = 10; all'indirizzo di memoria in cui e' contenuto y (dove in questo caso c'e' un intero, ecco perche' serve il tipo) vai a scrivere 10.
    possiamo anche scrivere: y[0] = 10; 
    */

    incr(y);
    incr(&x); //stessa cosa
    /*
    'x'. essendo una variabile locale, dovrebbe essere visibile solo nel main ma, 
    se passiamo il suo indirizzo di memoria, e' possibile vederlo anche esternamente al main.
    */

    printf("x ora e' %d:\n", x);

    int **z = &y; //un puntatore a un puntatore di un intero
    printf("y e' memorizzato nell'indirizzo: %p\n", z);

    printf("\n\n");
    printf("x e' grande: %d bytes,\ny e' grande: %d bytes,\nz e' grande: %d bytes\n",(int)sizeof(x), (int)sizeof(y), (int)sizeof(z));
    //tutti i puntatori sono normalmente grandi uguali, ovvero 8 byte.
    printf("\n\n");

    char mystr[] = "AABBCCDDEEFF";
    printf("%s\n", mystr);
    char *p = mystr;
    printf("in: %p posso vedere: '%s'\n", mystr, mystr);
    printf("%c%c\n\n", p[0], p[1]); //stampa: AA. 
    //printf("%c%c\n", *p, *(p+1));
    
    printf("Inizialmente p e' %p\n", p);
    while(*p != 0) {
        putchar(*p); //p[0]
        p++;
    }
    printf("\n");
    /*
    while(*p != E) {
        putchar(p[1]); //stampera' sempre il successivo
        p++;
    }
    */

    printf("successivamente p e' %p\n", p);
    
    char *ptr = mystr;

    printstr(ptr);
    printstr(mystr);
    printstr(mystr+3);

    printf("\n\n");

    /*
    short *p1 = (short*)mystr;
    p++;
    printf("%d\n", *p1);
    
    N.B.
    QUANDO INCREMENTO UN QUALSIASI PUNTATORE DI 1, IN REALTA' QUEL 1
    SARA' INIZIALMENTE MOLTIPLICATO PER LA GRANDEZZA DEL TIPO BASE DEL PUNTATORE
    quindi, in questo caso, se siamo sul primo A, e incrementiamo p di 4 (p += 4),
    non arriveremo alla seconda B. Ma, essendo lo short di 2 byte,
    arrivero' alla E.
    questo succede anche con p[4]
    */
    return 0;
}

//FUNZIONE STAMPA STRINGA
void printstr(char* p) {
    while(*p != 0) {
        putchar(p[0]); //*p
        p++;
    }
    printf("\n");
}