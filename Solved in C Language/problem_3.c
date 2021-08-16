
//Problem Description: Solve problem 2 with unsorted array.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 30

void printArray(int arr[])
{
    printf("\nArray:");
    for (int i = 0; i < ARRSIZE; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n\n");
}

int sumArray(int arr[])
{
    int i, sum = 0;
    for (i = 0; i < ARRSIZE; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void find(int arr[])
{
    int i;
    int count[ARRSIZE + 1];

    for (i = 0; i < ARRSIZE + 1; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < ARRSIZE; i++)
    {
        count[arr[i]] += 1;
    }

    for (i = 1; i < ARRSIZE + 1; i++)
    {
        if (count[i] > 1)
        {
            printf("Repeating Number: %d\n", i);
        }
        else if (count[i] == 0)
        {
            printf("Missing Number: %d\n", i);
        }
    }
    printf("\n");
}

int main(void)
{
    int arr[ARRSIZE], used[ARRSIZE];
    int i, n, rnd;

    srand(time(NULL));

    for (i = 0; i < ARRSIZE; i++)
    {
        arr[i] = 0;
    }

    n = 1;

    while (sumArray(used) != ARRSIZE)
    {
        rnd = rand() % ARRSIZE;
        if (used[rnd] != 1)
        {
            used[rnd] = 1;
            arr[rnd] = n;
            n++;
        }
    }

    do
    {
        rnd = rand() % ARRSIZE;
    } while ((arr[rnd] == rnd) || (rnd == 0));

    arr[rnd] = rnd;

    printArray(arr);
    find(arr);

    return 0;
}
