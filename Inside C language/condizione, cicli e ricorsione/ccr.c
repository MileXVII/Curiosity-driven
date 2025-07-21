#include <stdio.h>

void count(int, int );

int main(void){

//IF

    int i = 2;
    
    if (i > 3){ // {...} e' un blocco
        printf("i > 3\n");
    } else {
        printf("i <= 3\n");
    }

    /*SE ESEGUIAMO UN SINGOLO STATEMENT NON ABBIAMO BISOGNO DEI BLOCCHI

       1) if (i < 3) printf("i > 3\n");

        oppure

       2) if (i < 3) 
            printf("i > 3\n");

        oppure

       3)  if (i < 3){
            printf("i > 3\n");
            }

    MA ANCHE CON UN ELSE POSSIAMO OMETTERLI
        4) if (i > 3)
                printf("i > 3\n");
            else 
                printf("i <= 3\n");
    */

    //POSSIAMO METTERE UN BLOCCO OVUNQUE
    {
        int j = 5; //scopo lessicale interno al blocco
        printf("j is %d\n", j);
    }

    /*FUORI DAL BLOCCO NON FUNZIONERA'
            printf("j is %d\n", j);
    PERCHE' j E' LOCALE IN QUEL BLOCCO*/

    //ALTRO ESEMPIO 
    int x = 8;
        

    {
    int x = 5; //scopo lessicale (esiste) all'interno del blocco
    printf("\nfirst inner x is %d\n", x); //---> stampera' 5

        //stampiamo il suo indirizzo di memoria
        printf("first inner x (%zu bytes) is stored at %p\n",sizeof(x), &x);
    }

    {
    int x = 6; //scopo lessicale (esiste) all'interno del blocco
    printf("\nsecond inner x is %d\n", x); //---> stampera' 5

        //stampiamo il suo indirizzo di memoria
        printf("second inner x (%zu bytes) is stored at %p\n",sizeof(x), &x);
    }

    printf("\nouter x is %d\n", x); //---> stampera' 8
        //stampiamo il suo indirizzo di memoria
        printf("outer x (%zu bytes) is stored at %p\n\n\n",sizeof(x), &x);

//GOTO: CICLO DA 1 A 10
printf("\n\nciclo goto 1-10:\n\n");
    i = 0;

again:
    printf("%d\n", i);
    i++;
    if (i < 10) goto again;

/*CICLO INFINITO DI STAMPA CIAO IN BASIC
    l10: printf("ciao\n");
    l20: goto l10;
*/


//WHILE: CICLO DA 1 A 10
printf("\n\nciclo while 1-10:\n\n");
    i = 0;
    while(i <= 10){        
        printf("%d\n", i);
        i++;
    }; //anche senza ;


    
//WHILE IDENTICO IN GOTO
printf("\n\nciclo while trasmutato in goto:\n\n");
i = 0;
    loop:
    if (!(i <= 10)) goto next;
        printf("%d\n", i);
        i++;
        goto loop;
    next:

    printf("\n\n");

//CICLO FOR IDENTICO AL WHILE
printf("\n\nciclo while trasmutato in for:\n\n");

for(i = 0; i < 10; i++){  //se la variabile i e' stata gia' inizializzata possiamo ommetterla: for(; i<10; i++)
    printf("%d\n", i);
}

/*ciclo for omettendo tutto
i = 0;
for(;;;) //ciclo "infinito"    {   
    if(1>10) break; //la funzione break termina il ciclo nei cicli for/while e va nel prossimo ciclo annidato o esce se non presente. 
    printf("%d\n", i);
    i++;
}
*/

/*Possiamo scrivere il for in un sola riga
for(int i = 0; i < 10; i++) printf("%d\n", i);
... -> fuori dal ciclo (i non esiste piu' in questo caso)
*/


/*ciclo while "infinito"

while(1) //In C: 1 = vero, 0 = falso {
    ...
}
*/

/*CICLO DO WHILE
do  {
    ...
} while(condizione);

N.B. cicla la prima volta a prescindere
*/


printf("\n\n");
//SWITCH

i = 10;

switch(i)   {
    case 5: printf("E' un cinque\n"); break; //se non mettiamo il break eseguira' le prossime istruzioni fino al primo break trovato
    case 7: 
            printf("E' un sette\n"); break;
            printf("SI!! e' proprio un bel sette\n"); break;

    default: printf("Qualche altro numero\n"); break;
}

/*UGUALE A SCRIVERE

    if( i == 5) {
        ...
    } else if (i == 7) {
        ...
    } else { //default
        ...
    }

DIFFERENZA SOSTANZIALE: non possiamo dichiarare variabili all'interno dello switch a meno che non implementiamo un blocco 
*/



printf("\n\n");
//RICORSIONE
printf("\n\nciclo di conta 1-10 tramite funzione ricorsiva count:\n\n");
    count(0, 10);


    return 0;
}

void count(int start, int end)  {
    if(start > end) return;
    printf("%d\n", start);
    count(start+1,end);

    /*ANCHE SE RICHIAMA SE STESSA, OGNI VOLTA VERRANNO CREATE NUOVE VARIABILI START E END
    potrete visionarlo stampando all'inizio della funzione le celle di memoria corrispondendti con: printf("%p %p", &start, &end);
    detto cio' si puo' intuire che, anche se elegante, questa metodologia (programmazione funzionale) consuma molta memoria.
    */

/*MIGLIORIA CON GOTO PER USARE MOLTA MENO MEMORIA!!

iterate:
    if (start > end) return;
    printf("%d\n", start);
    start = start + 1; //possimao anche scrivere start++;
    goto iterate;


N.B. E' possibile fare cio' solo se la funzione e' di coda.
*/

/*

*/
}