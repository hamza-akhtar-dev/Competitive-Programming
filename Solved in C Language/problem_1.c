
//Problem Description: Sort an array of 0’s 1’s 2’s without using extra memory or sorting algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 10

void printArray(int arr[])
{
    printf("Array:");
    for (int i = 0; i < ARRSIZE; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

void sort(int arr[])
{
    int i, j, k;
    int count0 = 0, count1 = 0, count2 = 0;

    for (i = 0; i < ARRSIZE; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else if (arr[i] == 2)
        {
            count2++;
        }
    }

    i = 0;

    while (count0 != 0)
    {
        arr[i] = 0;
        count0--;
        i++;
    }

    while (count1 != 0)
    {
        arr[i] = 1;
        count1--;
        i++;
    }

    while (count2 != 0)
    {
        arr[i] = 2;
        count2--;
        i++;
    }
}

int main(void)
{
    int arr[ARRSIZE];

    srand(time(NULL));

    for (int i = 0; i < ARRSIZE; i++)
    {
        arr[i] = rand() % 3;
    }

    printf("\nBefore Sorting\n");
    printArray(arr);

    sort(arr);

    printf("\nAfter Sorting\n");
    printArray(arr);

    printf("\n");

    return 0;
}
