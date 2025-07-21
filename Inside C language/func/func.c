#include <stdio.h>

int sum(int a, int b){ //possiamo ache scrivere int sum(int, int)
    return a+b; //ritorna la somma intera tra a e b. N.B. il tipo deve essere coerente con il valore della funzione. //a e b sono parametri
    /* 
    return accetta espressioni: quindi anche 
    if(...){ } o while(...) { } etc.
    */

    /*POSSIAMO OVVIAMENTE ANCHE SCRIVERE:
    int c; //c e' una variabile locale.
    c = a + b;
    return c;
    */
}

//SECONDA FUNZIONE!!

int x = 0; //variabile globale, non perde lo stato

void incr(void){
    /*Possiamo sostituire la variabile globale, direttamente all'interno della funzione icnr, precedentemente dichiarata con:
    static int x = 0; anch'essa non perdera' lo stato.

    N.B. non sara' possibile richiamare 'x' all'interno del main perche' non e' piu' una variabile globale (e' interna alla funzione) anche se la funzione funziona allo stesso modo.
    */

    x = x + 1;
    printf("%d\n", x);
}

/*PROTOTIPO FUNZIONE PER RICHIAMARE LA FUNZIONE STESSA PRESENTE AL DI SOTTO DEL MAIN
int sum(int a, int b); 
oppure..
int sum(int, int);
*/


int main(){
    puts("Hello World!");


    printf("%d\n", sum(10, 20));//richiamiamo la funzione sum all'interno del nostro programma. //10 e 20 sono argomenti
    
    /*POSSIAMO ANCHE ASSEGNARE IL VALORE RITORNATO AD UNA VARIABILE
    int z = sum(30, 20); oppure int z = sum(a, b) con a,b variabili precedentemente inizializzate
    // z = e' una variabile locale.
    */

    incr(); //stampa 1
    incr(); //stampa 2
    incr(); //stampa 3
    incr(); //stampa 4


    int a = 10;
    double y = 1.7532;

    printf("%d %.4f\n", a, y); //%d per gli interi interi, %f o %lf per i double.  //printf("%x, %.4f", a, y) stampa "a, 1.7532", printf("%X, %.4f", a, y) stampa "A, 1.7532"   
    /*ATTENZIONE!! per la printf non cambia nulla perche' i float sono automaticamente passati a double (default argument promotion), 
    tuttavia nella scanf, %f "conserva" un float, mentre %lf un double*/


    return 0; //come detto nel file Hello World! lo 0 e' il valore di ritorno della funzione 'speciale' main..
}

/*POSSIAMO SCRIVERE LA FUNZIONE ANCHE SOTTO PER POI RICHIAMARLA SOPRA DUE VOLTE
ES:

int sum(int a, int b){
    return a+b;
}
*/