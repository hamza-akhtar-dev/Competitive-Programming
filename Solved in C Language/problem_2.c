
//Problem Description: Given an sorted array of size n. Array elements are in the range from 1 to n.
//One number from the set {1,2,...,n} is missing and one occurs twice in the array. Find these two numbers.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 1000

void printArray(int arr[])
{
    printf("\nArray:");
    for (int i = 0; i < ARRSIZE; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n\n");
}

void find(int arr[])
{
    int iter_sum = 0;
    int form_sum = 0;
    int i, n;

    for (i = 0; i < ARRSIZE; i++)
    {
        iter_sum += arr[i];
        n = i + 1;
        form_sum = ((n * (n + 1)) / 2);
        if (iter_sum != form_sum)
        {
            break;
        }
    }
    printf("Missing Number: %d\n\n", n);
    printf("Repeating Number: %d\n", arr[i]);
}

int main(void)
{
    int arr[ARRSIZE];
    int i, num;

    srand(time(NULL));

    for (i = 0; i < ARRSIZE; i++)
    {
        arr[i] = i + 1;
    }
    num = rand() % ARRSIZE;
    arr[num] = num + 2;

    printArray(arr);
    find(arr);

    return 0;
}
