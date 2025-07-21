#include <stdio.h>

int main(void){

   //char c = 10; intero di tipo char casting automatico in int
    char c = 'p'; //intero di tipo char, 
    //N.B. gli apici '' in c possono contenere solo un carattere

    //il carattere verra' espanso a un numero che rappresenta la posizione di quel carattere nello standard ASCII  
    printf("Hello World %d \n", c); 

    //Hello World come argomento
    printf("[%s]\n", "Hello World");

    //stampare il carattere
    printf("[%c%c%c%c]\n", 65, 'x', 67, 68);
    
    //array di tipo char (stringa)
    char str[6] = {'h', 'e', 'l', 'l', '0', 0}; //lo 0 senza apicetti oppure lo: "'\0'" e' il terminatore nullo
    //char str2[6] = "hell0";
    //char str2[] = "hell0"; il sizeof restituisce dimensione 6
    /*posso anche scrivere: 
    1) str[3] = 'X'; 
    2) str[3] = 58;
    3) str[3]++;
    e verra' sostituito il carattere presente nella posizione 3 dell'array di caratteri
    */
    printf("%s\n", str);
   
    //ciclo di stampa
    int i = 0;
    while(str[i] != 0){
        printf("%c", str[i]);
        i++;
    }
    printf("\n");

    //torniamo al nostro Hello World!
    char str2[6] = "hello"; //e' il programma a inserire automaticamente il terminatore nullo 
    printf("Hello World: %s %s\n", str, str2);



    return 0;
}