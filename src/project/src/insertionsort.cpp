#include "../header/project.h"
/**
 * @brief Sorts an array of integers using the Insertion Sort algorithm.
 *
 * This function sorts the given array of integers in ascending order using
 * the Insertion Sort algorithm. It iterates through the array, considering
 * one element at a time and inserting it into its correct position among the
 * previously sorted elements.
 *
 * @param number An array of integers to be sorted.
 * @details The function modifies the input array in place.
 */
void InsertionSort(std::istream& in, std::ostream& out, int number[5]) {
    int q = 1;
    for (int j = 1; j < 5; j++) {
        int key = number[j];
        int i = j - 1;
        while (i >= 0 && number[i] > key) {
            number[i + 1] = number[i];
            i = i - 1;
        }
        number[i + 1] = key;
        while (q < 1000) {
            out << q << ".step: ";
            q++;
            break;
        }
        for (int a = 0; a < 5; a++) {
            out << number[a] << " ";
        }
        out << "\n";
    }
}