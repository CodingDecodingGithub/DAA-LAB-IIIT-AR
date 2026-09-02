// partition point
#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int lastZero = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            lastZero = i;
        }
        else
        {
            break;
        }
    }
    printf("Partition index (last 0): %d\n", lastZero + 1);

    return 0;
}