#include "../header/project.h"
#include <iostream>
void Merge(std::ostream& out, int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;

    out << "Merged array from " << p << " to " << r << ": ";
    MergeSortPrintArray(out, A + p, r - p + 1);
}

void MergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(std::cout, A, p, q, r);
    }
}

void MergeSortPrintArray(std::ostream& out, int A[], int size) {
    for (int i = 0; i < size; i++) {
        out << A[i] << " ";
    }
    out << "\n";
}
