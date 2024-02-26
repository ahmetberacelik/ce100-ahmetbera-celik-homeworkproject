/**
 * @file project.h
 *
 * @brief Provides functions for math. utilities
 */

#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>

void menu(std::istream& in, std::ostream& out);

void InsertionSort(std::istream& in, std::ostream& out, int number[5]);

void Merge(std::istream& in, std::ostream& out, int A[], int p, int q, int r);

void MergeSort(int A[], int p, int r);

void MergeSortPrintArray(std::istream& in, std::ostream& out, int A[], int size);

#endif // PROJECT_H