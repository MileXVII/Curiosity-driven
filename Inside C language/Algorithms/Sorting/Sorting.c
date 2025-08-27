#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

static const int length = 10;

void error(const char *err) {
    if(errno != 0) {
        perror(err);
    } else {
        fprintf(stderr, "[ERROR]: %s!\n", err);
    }
    exit(EXIT_FAILURE);
}

void swap(int *array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void BubbleSort(int *array) {
    bool swapped = true;
    int limit = length - 1;
    while(swapped) {
        swapped = false;
        for(int i = 0; i < limit; i++) {
            if(array[i] > array[i + 1]) {
                swap(array, i, i + 1);
                swapped = true;
            }
        }
        limit--;
    }
}

void SelectionSort(int *array) {
    for(int index = 0; index < length - 1; index++) {
        int min = index;
        for(int i = index + 1; i < length; i++) {
            if(array[i] < array[min]) min = i;
        }
        swap(array, min, index);
    }
}

void InsertionSort(int *array) {
    for(int index = 1; index < length; index++) {
        int key = array[index];
        int position = index;

        while(position > 0 && array[position - 1] > key){
            array[position] = array[position - 1];
            position--;
        }
        array[position] = key;
    }
}

void print_Array(int *array) {
    int i = -1;
    while(++i < length) {
        printf("%d ", array[i]);
    }
    putchar('\n');
}


int main(void) {

    printf("\x1b[H\x1b[2J\x1b[3J");

    int array[] = {4, 2, 1, 3, 5, 0, 6, 8, 9, 7};

    if(length <= 0) {
        error("Invalid array length");
    }

    int choice = 0;
    do {
        puts("\nSelect Sorting algorithm: ");
        puts("[1]: BubbleSort");
        puts("[2]: SelectionSort");
        puts("[3]: InsertionSort");
        printf("Enter your choice: ");
        
        if(scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            puts("Invalid input! Please enter a number.");
            choice = 0;
        } else if(choice < 1 || choice > 3) {
            puts("Not valid option! Please choose 1, 2, or 3.");
        }
    } while(choice < 1 || choice > 3);
    printf("\x1b[H\x1b[2J\x1b[3J");

    switch(choice) {
        case 1:
            BubbleSort(array);
            break;
        case 2:
            SelectionSort(array);
            break;
        case 3:
            InsertionSort(array);
            break;
        default:
            error("Unexpected choice value");
    }
    
    print_Array(array);
    return 0;
}
