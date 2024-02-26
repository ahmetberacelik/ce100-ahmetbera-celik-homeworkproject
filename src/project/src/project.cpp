#include "../header/project.h"
#include <iostream>

void menu(std::istream& in, std::ostream& out) {
    int number[5];
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
    out << "Sorting with Insertion Sort: ";
    InsertionSort(number);
    for (int a = 0; a < 5; a++) {
        out << number[a] << " ";
    }
}