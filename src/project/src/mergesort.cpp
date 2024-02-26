#include "../header/project.h"
#include <iostream>
void Merge(std::ostream& out, int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    // Merge the temp arrays back into A[p..r]
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

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;

    // Print the current state of the array after merging
    out << "Merged array from " << p << " to " << r << ": ";
    MergeSortPrintArray(out, A + p, r - p + 1);
}

// Function to perform merge sort
void MergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2; // Find the middle point
        MergeSort(A, p, q); // Sort first half
        MergeSort(A, q + 1, r); // Sort second half
        Merge(std::cout, A, p, q, r); // Merge the sorted halves
    }
}

// Utility function to print the array
void MergeSortPrintArray(std::ostream& out, int A[], int size) {
    for (int i = 0; i < size; i++) {
        out << A[i] << " ";
    }
    out << "\n";
}
