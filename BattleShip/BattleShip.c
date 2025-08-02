#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define GRID_COLS 10
#define GRID_ROWS 10
#define GRID_CELLS (GRID_COLS * GRID_ROWS)
#define BOAT 'o'
#define DESTROYED 'x'
#define SHOT '*'
#define CLEAR '.'

typedef enum {
    HORIZONTAL = 0,
    VERTICAL = 1
} Direction;

void error(char* err) {
    fprintf(stderr, "[ERROR]: %s!\n", err);
    exit(1);
}

int cell_to_index(int x, int y);
void set_cell(char *grid, int x, int y, char state);
char get_cell(char* grid, int x, int y);
void print_grids_side_by_side(char* grid1, char* username1, char* grid2, char* username2, int hide_opponent_boats);
void set_grid(char* grid, char state);
int can_place_boat(char* grid, int x, int y, int size, Direction dir);
void place_boat(char* grid, int x, int y, int size, Direction dir);
int generate_random_boats(char* grid, int min_size, int max_size, int num_boats);
int count_boats_in_grid(char* grid);
int count_remaining_boats(char* grid);
void computer_turn_intelligent(char* player_grid);


int main(void) {
play: //play again (goto)
    printf("\x1b[H\x1b[2J\x1b[3J");

    char my_grid[GRID_CELLS];
    char opponent_grid[GRID_CELLS];
    char username[21];
    int boat_max_size;
    int boat_min_size;

    do{
    puts("Username: ");
    if(!scanf("%20s", username)) error("Scanf of username failed");
    if(strlen(username) > 20) puts("Too long username");
    }while(strlen(username) > 20);

    do{
    puts("Boat max size: ");
    if(!scanf("%d", &boat_max_size)) error("Scanf of boat_max_size failed");
    if(boat_max_size > (GRID_COLS/2)) puts("Too Big value");
    if(boat_max_size < 2) puts("Too Low value");
    }while(boat_max_size > (GRID_COLS/2) || boat_max_size < 2);

    do{
    puts("Boat min size: ");
    if(!scanf("%d", &boat_min_size)) error("Scanf of boat_min_size failed");
    if(boat_min_size > boat_max_size) puts("Too Big value");
    if(boat_min_size <= 0) puts("Too Low value");
    }while(boat_min_size > boat_max_size || boat_min_size <= 0);

    set_grid(my_grid, CLEAR);
    set_grid(opponent_grid, CLEAR);
    
    /* Calculate boats number */
    float avg_boat_size = (boat_min_size + boat_max_size) / 2.0;
    int estimated_boats = (int)(GRID_CELLS / (avg_boat_size + 3));

    printf("Trying to insert %d boats...\n", estimated_boats);

    /* Generate random boats for player grid */
    int actual_boats_player = generate_random_boats(my_grid, boat_min_size, boat_max_size, estimated_boats);
    
    /* Generate random boats for opponent grid */
    int actual_boats_opponent = generate_random_boats(opponent_grid, boat_min_size, boat_max_size, estimated_boats);
do{
    printf("\x1b[H\x1b[2J\x1b[3J");
    printf("\n-----Welcome: %s-----\n", username);
    printf("Player boats positioned: %d\n", actual_boats_player);
    printf("Player boat cells: %d\n", count_boats_in_grid(my_grid));
    printf("Opponent boats positioned: %d\n", actual_boats_opponent);
    printf("Opponent boat cells: %d\n", count_boats_in_grid(opponent_grid));
    printf("\n-----GRID INFO-----\n");
    printf("BOAT: %c\n", BOAT);
    printf("BOAT DESTROYED: %c\n", DESTROYED);
    printf("SHOT: %c\n", SHOT);
    printf("CLEAR CELL: %c\n\n", CLEAR);

    print_grids_side_by_side(my_grid, username, opponent_grid, "opponent", 1);

    int x, y;
    printf("Select a target: (x, y)\n");

    while (1) {
        printf("x (0-%d): ", GRID_COLS - 1);
        if (scanf("%d", &x) != 1) {
            printf("Not valid input.\n");
            while (getchar() != '\n'); 
            continue;
        }

        printf("y (0-%d): ", GRID_ROWS - 1);
        if (scanf("%d", &y) != 1) {
            printf("Not valid input.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (x < 0 || x >= GRID_COLS || y < 0 || y >= GRID_ROWS) {
            printf("Coordinates out of the grid! Try again.\n");
            continue;
        }

        break; 
    }


    char target_cell = get_cell(opponent_grid, x, y);

    if (target_cell == BOAT) {
        set_cell(opponent_grid, x, y, DESTROYED);
        printf("hit!\n");

        if (count_remaining_boats(opponent_grid) == 0) {
            printf("\x1b[H\x1b[2J\x1b[3J");
            printf("Congratulation %s! You won!\n", username);

            char choice;
            do{
            puts("Play again? (y/n)");
            if(!scanf(" %c", &choice)) {
                puts("[ERROR]: Scanf of choice failed");
                continue;
            }

            switch(choice) {
                case 'y':
                    goto play; 
                    break; //security
                case 'n':
                    exit(0);
                default:
                    puts("Not valid option!");
                    continue;
            };

            }while(choice != 'n');
            break; 
        }
    } else if (target_cell == CLEAR) {
        set_cell(opponent_grid, x, y, SHOT);
        printf("Missed!\n");
    } else {
        printf("Already shot at this position!\n");
    }

    computer_turn_intelligent(my_grid);

    if (count_remaining_boats(my_grid) == 0) {
    print_grids_side_by_side(my_grid, username, opponent_grid, "opponent", 0);
    printf("You lose! Opponnet have detroyed all your ship.\n");

    char choice;
    do {
        puts("Play again? (y/n)");
        if (!scanf(" %c", &choice)) {
            puts("[ERROR]: Scanf of choice failed");
            continue;
        }

        switch (choice) {
            case 'y':
                goto play;
            case 'n':
                exit(0);
            default:
                puts("Not valid option!");
        }
    } while (choice != 'n');
}


    }while(1);

    return 0;
}

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

/* Displays the grid on the screen. */
void print_grid(char* grid, char* username) {
    
    printf(" %s:\n", username);
    for(int y = 0; y < GRID_ROWS; y++){
        for(int x = 0; x < GRID_COLS; x++){
            printf("%c", get_cell(grid,x,y));
        }
        printf("\n");
    }
}

/* Displays two grids side by side on the screen. */
void print_grids_side_by_side(char* grid1, char* username1, char* grid2, char* username2, int hide_opponent_boats) {
    int spacing = 5; /* Space between grids */
    
    /* Print headers */
    printf(" %-*s%*s%s\n", GRID_COLS, username1, spacing, "", username2);
    
    /* Print grids row by row */
    for(int y = 0; y < GRID_ROWS; y++){
        /* Print first grid row */
        for(int x = 0; x < GRID_COLS; x++){
            printf("%c", get_cell(grid1, x, y));
        }
        
        /* Print spacing */
        for(int i = 0; i < spacing; i++){
            printf(" ");
        }
        
        /* Print second grid row */
        for(int x = 0; x < GRID_COLS; x++){
            char cell = get_cell(grid2, x, y);
            if (hide_opponent_boats && cell == BOAT) {
                printf("%c", CLEAR); // nascondi le barche
            } else {
                printf("%c", cell);
            }
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

/* Checks if it's possible to place a boat at the specified position. */
int can_place_boat(char* grid, int x, int y, int size, Direction dir) {
    /* Check if the boat goes out of the grid boundaries */
    if (dir == HORIZONTAL) {
        if (x + size > GRID_COLS) return 0;
    } else {
        if (y + size > GRID_ROWS) return 0;
    }
    
    /* Check if there's free space for the boat and the safety border */
    for (int i = -1; i <= size; i++) {
        for (int j = -1; j <= 1; j++) {
            int check_x, check_y;
            
            if (dir == HORIZONTAL) {
                check_x = x + i;
                check_y = y + j;
            } else {
                check_x = x + j;
                check_y = y + i;
            }
            
            /* Check only valid cells (without wrapping for the check) */
            if (check_x >= 0 && check_x < GRID_COLS && 
                check_y >= 0 && check_y < GRID_ROWS) {
                if (get_cell(grid, check_x, check_y) != CLEAR) {
                    return 0; /* Space occupied */
                }
            }
        }
    }
    return 1; /* Valid position */
}

/* Places a boat in the grid. */
void place_boat(char* grid, int x, int y, int size, Direction dir) {
    for (int i = 0; i < size; i++) {
        if (dir == HORIZONTAL) {
            set_cell(grid, x + i, y, BOAT);
        } else {
            set_cell(grid, x, y + i, BOAT);
        }
    }
}

/* Generates and places all boats randomly. */
int generate_random_boats(char* grid, int min_size, int max_size, int num_boats) {
    static int seed_initialized = 0;
    if (!seed_initialized) {
        srand(time(NULL)); /* Initialize random number generator */
        seed_initialized = 1;
    }
    
    int boats_placed = 0;
    int max_attempts = 1000; /* Avoid infinite loops */
    
    for (int boat = 0; boat < num_boats && max_attempts > 0; max_attempts--) {
        /* Generate random size */
        int size = min_size + rand() % (max_size - min_size + 1);
        
        /* Generate random direction */
        Direction dir = rand() % 2;
        
        /* Generate random position */
        int x = rand() % GRID_COLS;
        int y = rand() % GRID_ROWS;
        
        /* Try to place the boat */
        if (can_place_boat(grid, x, y, size, dir)) {
            place_boat(grid, x, y, size, dir);
            boats_placed++;
            printf("Boat %d placed: size %d, position (%d,%d), %s\n", 
                   boats_placed, size, x, y, (dir == HORIZONTAL) ? "horizontal" : "vertical");
        }
    }
    
    if (boats_placed < num_boats) {
        printf("Warning: placed only %d boats out of %d requested\n", boats_placed, num_boats);
    }
    
    return boats_placed;
}

/* Utility function to count boats in the grid. */
int count_boats_in_grid(char* grid) {
    int count = 0;
    for (int y = 0; y < GRID_ROWS; y++) {
        for (int x = 0; x < GRID_COLS; x++) {
            if (get_cell(grid, x, y) == BOAT) {
                count++;
            }
        }
    }
    return count;
}

/*Utility function to check remaining boats. */
int count_remaining_boats(char* grid) {
    int count = 0;
    for (int y = 0; y < GRID_ROWS; y++) {
        for (int x = 0; x < GRID_COLS; x++) {
            if (get_cell(grid, x, y) == BOAT) {
                count++;
            }
        }
    }
    return count;
}

/*Opponent turn*/
void computer_turn_intelligent(char* player_grid) {
    static int target_x = -1, target_y = -1;
    static int directions_tried[4] = {0}; // N, E, S, W
    static int has_target = 0;

    int x, y;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

    if (has_target) {
        // select nearby shotted target
        for (int dir = 0; dir < 4; dir++) {
            if (directions_tried[dir]) continue; // position already shot

            int nx = target_x + dx[dir];
            int ny = target_y + dy[dir];

            if (nx < 0 || nx >= GRID_COLS || ny < 0 || ny >= GRID_ROWS) {
                directions_tried[dir] = 1;
                continue;
            }

            char cell = get_cell(player_grid, nx, ny);
            if (cell == CLEAR) {
                set_cell(player_grid, nx, ny, SHOT);
                printf("Computer missed at (%d,%d)\n", nx, ny);
                directions_tried[dir] = 1;
                return;
            } else if (cell == BOAT) {
                set_cell(player_grid, nx, ny, DESTROYED);
                printf("Computer hit again at (%d,%d)!\n", nx, ny);
                target_x = nx;
                target_y = ny;
                for (int i = 0; i < 4; i++) directions_tried[i] = 0; // Reset to new center
                return;
            } else {
                // SHOT o DESTROYED
                directions_tried[dir] = 1;
                continue;
            }
        }

        // reset target if there aren't util target
        has_target = 0;
    }

    //casual shot (when there isn't a target)
    do {
        x = rand() % GRID_COLS;
        y = rand() % GRID_ROWS;
    } while (get_cell(player_grid, x, y) == SHOT || get_cell(player_grid, x, y) == DESTROYED);

    char cell = get_cell(player_grid, x, y);
    if (cell == BOAT) {
        set_cell(player_grid, x, y, DESTROYED);
        printf("Computer hit at (%d,%d)!\n", x, y);
        target_x = x;
        target_y = y;
        has_target = 1;
        for (int i = 0; i < 4; i++) directions_tried[i] = 0;
    } else {
        set_cell(player_grid, x, y, SHOT);
        printf("Computer missed at (%d,%d)\n", x, y);
    }
}

