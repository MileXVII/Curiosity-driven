/* Conway's Game of Life
   Conway's Game of Life is a "game" invented in 1970 by British mathematician John Conway.
   It follows very simple rules that nevertheless generate surprising results.
   Rather than a game, it's a two-dimensional universe made of cells (think of them as bits) arranged in a 2D grid (x, y).
   These grid cells can be alive/on (white, state 1), or dead/off (black, state 0).
   Each given state of the game grid evolves into the next state by applying the same simple rules to every cell.

   1) A live cell will remain alive in the next iteration if it has 2–3 live neighbors (out of the 8 surrounding it).
   2) A dead cell becomes alive if it has exactly 3 live neighbors.

   Note: This code is written using only knowledge acquired so far. It could definitely be improved using arrays and pointers.
   Only two pointers are used here, and their usage does not require deep understanding.
*/

#include <stdio.h>
#include <unistd.h>

#define GRID_COLS 20
#define GRID_ROWS 20
#define GRID_CELLS (GRID_COLS * GRID_ROWS)
#define ALIVE '*'
#define DEAD '.'

/* Translates the specific point (x, y) into the corresponding index of a linear array.
   This function implements wrapping, so both negative and out-of-bound positive coordinates
   are wrapped around cyclically. */
int cell_to_index(int x, int y) {
    // If the number is negative, we want to add GRID_COLS/ROWS until it becomes positive
    if (x < 0){
        x = (-x) % GRID_COLS; // normalized with clock arithmetic
        x = GRID_COLS - x;
    }
    if (y < 0){
        y = (-y) % GRID_ROWS;
        y = GRID_ROWS - y;
    }
    if(x >= GRID_COLS) x = x % GRID_COLS; // If greater than GRID_COLS, subtract GRID_COLS until within bounds
    if(y >= GRID_ROWS) y = y % GRID_ROWS;

    return y * GRID_COLS + x;
}

/* Sets the specific cell at position (x, y) to the given state. */
void set_cell(char *grid, int x, int y, char state) {
    grid[cell_to_index(x,y)] = state; 
}

/* Returns the state of the cell at position (x, y). */
char get_cell(char* grid, int x, int y) {
    return grid[cell_to_index(x,y)];
}

/* Displays the grid on the screen, clearing the terminal using the required VT100 escape sequence. */
void print_grid(char* grid) {
    printf("\x1b[H\x1b[2J\x1b[3J"); // Clear screen via escape sequence, same as running "clear | xxd" on WSL
    for(int y = 0; y < GRID_ROWS; y++){
        for(int x = 0; x < GRID_COLS; x++){
            printf("%c", get_cell(grid,x,y));
        }
        printf("\n");
    }
}

/* Sets all cells of the grid to the specified state. */
void set_grid(char* grid, char state) {
    for(int y = 0; y < GRID_ROWS; y++){
        for(int x = 0; x < GRID_COLS; x++){
            set_cell(grid, x, y, state);
        }
    }
}

/* Returns the number of live neighboring cells of the cell at (x, y). */
int count_living_neighbors(char* grid, int x, int y) {
    int alive = 0;
    for (int yo = -1; yo <= 1; yo++) {
        for (int xo = -1; xo <= 1; xo++) {
            if (xo == 0 && yo == 0) continue; // skip the cell itself
            if (get_cell(grid, x + xo, y + yo) == ALIVE) alive++;
        }    
    } 
    return alive;
}

/* Computes the next state of the Game of Life according to its rules. */
void compute_new_state(char *old, char *new) {
    for(int y = 0; y < GRID_ROWS; y++){
        for(int x = 0; x < GRID_COLS; x++){
            int n_alive = count_living_neighbors(old, x, y);
            int new_state = DEAD;
            if (get_cell(old, x, y) == ALIVE) {
                if (n_alive == 2 || n_alive == 3) 
                    new_state = ALIVE;
            } else {
                if (n_alive == 3)
                    new_state = ALIVE;
            }
            set_cell(new, x, y, new_state);
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

    char *old = old_grid;
    char *new = new_grid;

    while(1) { // glider loop
        compute_new_state(old, new);
        print_grid(new);
        usleep(100000);

        // Swap the two pointers
        char *tmp = old;
        old = new;
        new = tmp;
    }

    return 0;
}
