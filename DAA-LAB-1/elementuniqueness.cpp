// element uniqueness

#include <stdio.h>

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int found = 0;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                printf("Duplicate element found\n");
                found = 1;
                break;
            }
        }

        if(found)
        {
            break;
        }
    }

    if(!found)
    {
        printf("No duplicates found.\n");
    }

    return 0;
}