/*PREMESSA:
E' IMPORTANTE VISIONARE OGNI ELABORATO PRESENTE DAL PRIMO ALL'ULTIMO. LA MAGGIOR PARTE DEL LAVORO E DELLE COMPETENZE VANNO TUTTAVIA ACQUISITE AUTONOMAMENTE.
*/


#include <stdio.h> //file.h 1) h sta per header 2)sono file di intestazione inclusi per includere comandi non facenti parte originariamente del c (come la printf())
//N.B. possiamo anche scrivere #include "file.c"

/*N.B possiamo in questo specifico programma non includere <stidio.h> ma scrivere solamente il prototipo della funzione printf, ovvero: 
int printf(const char * restrict format, ...);
il prototipo della funzione potra' essere preso da linea di comando wsl, con il comando:
man 3 printf 
che andra' a prendere il 'manuale' (a pagina 3 (non sempre!!)) della funzione printf(); 
N.B. man non e' presente nel powershell 
*/

int main(){ //int main = funzione di tipo int che si aspetta un valore di ritorno int //int main(){} = int main(void){} con parametro void "sotto inteso"

    printf("Hello World! \n"); //puts("x"); = printf("x\n"); (piu' performante nel caso si volesse semplicemente stampare una parola)

    return 0; //int di ritorno per la variabile main 
    /*ATTENZIONE!!
    nei compilatori moderni di c anche se non scriviamo return 0 non succede nulla ma e' buona pratica scriverlo comunque, in C++ da errore.
    volendo si potrebbe utilizzare la sintassi: void main() { }.
    Il return 0 serve a segnalare al sistema operativo se il programma ha avuto un buon esito o meno.
    La convenzione su unix e' che se il programma ritorna 0 e' andata bene, se ritorna 1, 2, 3 ecc.. (per segnalare diversi tipi di errori), vorra' dire che la compilazione e' fallita.
    */

    /*
    per stampare il valore del ritorno, es: "return 0", dopo aver eseguito il programma con: "./out", scrivere: "echo $?", in questo caso stampera': "0" oppure direttamente: "./out; echo $?".
    
    e' possibile anche scrivere: "./out && ls", se ritorna 0 ls verra' eseguito, altrimenti, se ritorna altro, no. Provare autonomamente per vedere la differenza di output. 
    cio' e' utile nel caso volessi runnare sequenzialmente piu' programmi con la notazione: "&&", nel caso di un errore di ritorno si fermerebbe e non continuerebbe l'esecuzione dei programmi successivi.

    possiamo entrare nella modalita' matematica del terminale scrivendo il comando: 'bc', per uscire dalla modalita' matematica dovremo scrivere 'quit'
    */
}

/* ESEMPIO file.c
nel 'file.c' avremo solo = printf("Hello World! \n");

int main(){
    #include "file.c"
    return 0;
}
*/

/*RUNNARE IL PROGRAMMA (SU VS CODE):
PowerShell: 
    1) cd \Percorso\ (ES: cd C:\Users\micha\OneDrive\Desktop\C)
    2) gcc -Wall -O2 nome_file.c -o nome_file (creera' un .exe)
    3) .\nome_file
WSL:
N.B. possibilmente non avrai gcc installato, aggiorna i pacchetti con: 'sudo apt update', poi installa gcc con: 'sudo apt install gcc'
    1) cd /Percorso/ (ES: cd mnt/c/Users/micha/Onedrive/Desktop/c)
    2) gcc -Wall -O2 nome_file.c -o nome_file (creera' un file senza estensione eseguibile solamente da riga di comando)
    3) ./nome_file
specifiche del '-':
    1) -Wall & -W (non presente) (mostrano tutti i warning piu' comuni)
    2) -O2 (runna con una ottimizzazione di livello 2 che fara' si che il compilatore si accorgera' di cose che possiamo scrivere meglio e lo runnera ottimizzato)
    N.B. migliorie visibili creando un file Assembly del programma runnandolo con '-S'
    3) -o nome_file (indica il nome del file eseguibile che verra' generato.)
*/