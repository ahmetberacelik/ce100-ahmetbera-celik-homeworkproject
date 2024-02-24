#include "../header/insertionsort.h"
#include "../header/project.h"
#include <stdio.h>

void menu() {
    int number[5];
    printf("Please enter 5 numbers: \n");
    for (int i = 0; i < 5;) {
        printf("Please enter %d. number: ", i + 1);
        if (scanf("%d", &number[i]) == 1) {
            i++;
        }
        else {
            printf("Error: Please enter a valid number.\n");
            while (getchar() != '\n');
        }
    }
    printf("Sorting with Insertion Sort: ");
    InsertionSort(number);
    for (int a = 0; a < 5; a++) {
        printf("%d ", number[a]);
    }
    printf("\nSorting with Merge Sort: ");
}