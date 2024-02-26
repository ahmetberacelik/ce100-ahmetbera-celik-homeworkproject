#include "../header/project.h"
#include <iostream>
void SelectionSort(std::ostream& out, int A[], int size) {
    for (int j = 0; j < size - 1; ++j) {
        int smallest = j;
        for (int i = j + 1; i < size; ++i) {
            if (A[i] < A[smallest]) {
                smallest = i;
            }
        }
        if (smallest != j) {
            int temp = A[j];
            A[j] = A[smallest];
            A[smallest] = temp;
        }
        out << (j + 1) << ".step: ";
        for (int a = 0; a < size; a++) {
            out << A[a] << " ";
        }
        out << "\n";
    }
}
