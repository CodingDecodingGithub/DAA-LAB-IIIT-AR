// bubble sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubble(int a[], int n, int flag)
{
    int comp = 0;

    for(int i = 0; i < n - 1; i++)
    {
        int swap = 0;

        for(int j = 0; j < n - i - 1; j++)
        {
            comp++;

            if(a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swap = 1;
            }
        }

        if(flag && swap == 0)
            break;
    }

    return comp;
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n], b[n];

    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        b[i] = a[i];
    }

    int c1 = bubble(a, n, 1);
    int c2 = bubble(b, n, 0);

    printf("Optimized Bubble Sort Comparisons = %d\n", c1);
    printf("Normal Bubble Sort Comparisons = %d\n", c2);

    return 0;
}