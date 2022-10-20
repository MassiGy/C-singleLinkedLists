#include "../headers/arrays.h"

void initArray(int *head, int size)
{
    for (int i = 0; i < size; ++i)
    {
        head[i] = 0;
    }
}

void listArray(int *head, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("@%i: %i\n", i, head[i]);
    }
}

void fillArray(int *head, int size)
{
    for (int i = 0; i < size; ++i)
    {
        *(head + i) = (int)rand() % 100;
    }
}

int getMax(int *head, int size)
{
    int max = *head;

    for (int i = 0; i < size; ++i)
    {
        if (*(head + i) > max)
        {
            max = *(head + i);
        }
    }

    return max;
}

float getAverage(int *head, int size)
{
    int sum = 0;

    for (int i = 0; i < size; ++i)
    {
        sum += *(head + i);
    }

    return (float)sum / size;
}

bool liniarSearch(int *head, int size, int val)
{
    bool res = false;
    for (int i = 0; i < size; ++i)
    {
        if (*(head + i) == val)
        {
            res = true;
            break;
        }
    }
    return res;
}

bool binarySearch(int *head, int first, int last, int val)
{
    bool resault = false;

    if (val < head[0] || val > head[last])
    {
        return resault;
    }

    if (head[first] == val || head[last] == val)
    {
        resault = true;
        return resault;
    }

    if (first == last)
    {
        return resault;
    }

    int mid = (first + last) / 2;

    if (head[mid] > val)
    {
        resault = binarySearch(head, first, mid - 1, val);
    }
    else
    {
        resault = binarySearch(head, mid + 1, last, val);
    }

    return resault;
}

void bubleSort(int *head, int size)
{
    if (size <= 1)
        return;

    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (*(head + j) < *(head + i))
            {
                // swap
                int temp = head[j];
                head[j] = head[i];
                head[i] = temp;
            }
        }
    }
}

void selectionSort(int *head, int size)
{
    assert(head != NULL);
    assert(size > 1);

    // initiate the max index ;
    int maxIndex = 0;

    for (int i = 0; i < size; ++i)
    {
        int j;
        for (j = 0; j < size - i - 1; ++j)
        {
            if (*(head + j) > *(head + maxIndex))
            {
                maxIndex = j;
            }
        }

        // swap the max and the last element value

        int temp = *(head + j);
        *(head + j) = *(head + maxIndex);
        *(head + maxIndex) = temp;
    }
}
/*
int *mergeSort(int *resault, int *head, int size)
{
    assert(head != NULL);
    assert(size >= 1);

    if (size < 2)
    {
        return head;
    }

    int half = size / 2;

    int *left = mergeSort(resault, head, half);
    int *right = mergeSort(resault, &head[size - half], size - half);

    return mergeBySorting(resault, left, half, right, size - half);
}

int *mergeBySorting(int *resault, int *left, int left_length, int *right, int right_length)
{

    assert(left != NULL);
    assert(right != NULL);

    assert(left_length > 0 && right_length > 0);

    int left_size = left_length;
    int right_size = right_length;

    int counter = 0;
    int left_walker = 0;
    int right_walker = 0;

    while (left_size && right_size)
    {
        if (left[left_walker] < right[right_walker])
        {
            resault[counter] = left[left_walker];
            left_walker++;
            left_size--;
        }
        else
        {
            resault[counter] = right[right_walker];
            right_walker++;
            right_size--;
        }
        counter++;
    }

    if (left_size)
    {
        resault[counter] = left[left_walker - 1];
    }
    if (right_size)
    {
        resault[counter] = right[right_walker - 1];
    }

    return resault;
}

*/