/*Conway's Game Of Life
Il Conway's Game Of Life e' un "gioco"  inventato nel 1970 dal matematico inglese John Conway.
Ha delle semplicissime regole che pero' generano dei risultati sorprendenti.
Piu' che un gioco e' un universo bidimensionale composto da celle (pensiamole come bit) in una griglia bidimensionale (x, y) e 
queste celle della griglia possono essere vere/accese quindi nere nello stato 1, o morte/spente quindi bianche nello stato 0.
Ogni dato stato della griglia di gioco, eseguendo sempre le stesse semplicissime regole su ogni cella, da vita al prossimo stato.

1) Una cella viva nella prossima iterazione, sara' sempre viva se ha 2-3 vicini (8 celle nel suo contorno) vivi.
2) Le celle morte diventano vive se hanno esattamente 3 vicini vivi.

N.B. Questo codice e' scritto utilizzando solamente le competenze apprese fino ad ora, si potrebbe sicuramente migliorare con l'utilizzo di matrici e puntatori.
Solamente un puntatore e' presente che tuttavia non ci impone di sapere effettivamente l'utilizzo.
*/

#include  <stdio.h>
#include <unistd.h>

#define GRID_COLS 20
#define GRID_ROWS 20
#define GRID_CELLS (GRID_COLS*GRID_ROWS)
#define ALIVE '*'
#define DEAD '.'

/*traduci il punto specifico (x,y) nella corrispondente posizione dell'array lineare.
Questa funzione implementa il wrapping, quindi sia le coordinate negative che quelle
positive fuori dai limiti della griglia verranno fatte rientrare ciclicamente. */
int cell_to_index(int x, int y) {
    /* se ho un numero negativo vorrei aggiungere GRID_COLS/ROWS fino a quando il numero non diventa positivo */
    if (x < 0){
        x = (-x) % GRID_COLS; //normalizzato tramite la matematica dell'orologio
        x = GRID_COLS - x;
    }
    if (y < 0){
        y = (-y) % GRID_ROWS;
        y = GRID_ROWS - y;
    }
    if(x >= GRID_COLS) x = x % GRID_COLS; //ogni volta che ho un numero superiore a 25 vorrei sottrare 25 fino a quando non ho n numero inferiore a 25 per vedere quanto sono andato oltre.
    if(y >= GRID_ROWS) y = y % GRID_ROWS;

    return y*GRID_COLS+x;
}

/*La funzione setta la specifica cella nella posizione (x,y) nello stato specificato. */
void set_cell(char *grid, int x, int y, char state) {
    grid[cell_to_index(x,y)] = state; 
}

/*La funzione ritorna lo stato della griglia alla posizione (x,y). */
char get_cell(char* grid, int x, int y) {
    return grid[cell_to_index(x,y)];
}
/*Mostra la griglia nello schermo, pulendo il terminale usando la seguenza di escape richiesta VT100 */
void print_grid(char* grid) {
    printf("\x1b[H\x1b[2J\x1b[3J"); //Clear screen tramite sequenza di escape ottenuta tramite comando WSL: "clear | xxd"
    for(int y = 0; y < GRID_ROWS; y++){
        for(int x = 0; x < GRID_COLS; x++){
            printf("%c", get_cell(grid,x,y));
        }
            printf("\n");
    }
}
/*Sett tutte le celle della grigla nello stato specificato*/
void set_grid(char* grid, char state) {
    for(int y = 0; y < GRID_ROWS; y++){
        for(int x = 0; x < GRID_COLS; x++){
            set_cell(grid,x,y, state);
        }
    }
}
/*Ritorna il numero delle celle in vita vicine di (x, y)*/
int count_living_neighbors(char* grid, int x, int y) {
    int alive = 0;
    for (int yo = -1; yo<= 1; yo++) {
        for (int xo = -1; xo<= 1; xo++) {
            if(xo == 0 && yo == 0) continue; //salta questo ciclo
            if (get_cell(grid,x+xo,y+yo) == ALIVE) alive++;
        }    
    } 
        return alive;
}

/*Computa il nuovo stato del Game Of Life in accordo con le sue regole */
void compute_new_state(char *old, char *new) {
    for(int y = 0; y < GRID_ROWS; y++){
        for(int x = 0; x < GRID_COLS; x++){
            int n_alive = count_living_neighbors(old,x,y);
            int new_state = DEAD;
            if (get_cell(old,x,y) == ALIVE) {
                if (n_alive == 2 || n_alive == 3) 
                    new_state = ALIVE;
                }   else {
                    if (n_alive == 3)
                        new_state = ALIVE;
                }
                set_cell(new, x,y, new_state);
        } 
            
    }
}


int main(void)  {

char old_grid[GRID_CELLS];
char new_grid[GRID_CELLS];
set_grid(old_grid, DEAD);
set_cell(old_grid, 10, 10, ALIVE);
set_cell(old_grid, 9, 10, ALIVE);
set_cell(old_grid, 11, 10, ALIVE);
set_cell(old_grid, 11, 9, ALIVE);
set_cell(old_grid, 10, 8, ALIVE);
while(1) { //ciclo slider
compute_new_state(old_grid, new_grid);
print_grid(new_grid);
usleep(100000);
compute_new_state(new_grid, old_grid);
print_grid(old_grid);
usleep(100000);
}

return 0;
}