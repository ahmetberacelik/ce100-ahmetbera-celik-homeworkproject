#include "../header/project.h"
#include <iostream>

void menu(std::istream& in, std::ostream& out) {
    int number[5];
    int number_size = sizeof(number) / sizeof(number[0]);
    out << "Please enter 5 numbers: \n";
    for (int i = 0; i < 5;) {
        out << "Please enter " << i + 1 << ". number: ";
        if (in >> number[i]) {
            i++;
        }
        else {
            out << "Error: Please enter a valid number.\n";
            in.clear();
            in.ignore(1000, '\n');
        }
    }
    out << "--------------------------------------------------\n";
    out << "Sorting with Insertion Sort: \n";
    InsertionSort(out, number);
    out << "Insertion Sort Result: ";
    for (int a = 0; a < 5; a++) {
        out << number[a] << " ";
    }
    out << "\n";
    out << "Sorting with Merge Sort: \n";
    MergeSort(number, 0, number_size - 1);
    out << "Merge Sort Result: ";
    MergeSortPrintArray(out, number, number_size);
    out << "Sorting with Selection Sort: \n";
    SelectionSort(out, number, number_size);
    out << "Selection Sort Result: ";
    for (int a2 = 0; a2 < 5; a2++) {
        out << number[a2] << " ";
    }
}