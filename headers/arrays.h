#include "./sys_headers.h"


void initArray(int *head, int size);
void listArray(int *head, int size);
void fillArray(int *head, int size);
int getMax(int *head, int size);
float getAverage(int *head, int size);

/*ADVANCED*/
bool liniarSearch(int *head, int size, int val);
bool binarySearch(int *head, int first, int last, int val);
void bubleSort(int *head, int size);
void selectionSort(int *head, int size);

// // to (re)implement
// int *mergeSort(int *resault, int *head, int size);
// int *mergeBySorting(int *resault, int *left, int left_length, int *right, int right_length);
