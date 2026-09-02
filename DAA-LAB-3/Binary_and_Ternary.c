#include <stdio.h>
#include <stdlib.h>

long comparisons;

int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        comparisons++;
        if (arr[mid] == x)
            return mid;
        else if(arr[mid] < x)
            low = mid + 1;
        else{
            high = mid - 1;
        
        }
    }

    return -1;
}

int ternarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        comparisons++;
        if (arr[mid1] == x)
            return mid1;

        comparisons++;
        if (arr[mid2] == x)
            return mid2;

        comparisons++;
        if (x < arr[mid1])
            high = mid1 - 1;
        else if (x > arr[mid2])
            low = mid2 + 1;
        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}

void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void sortedArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {
    int n, x;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    fillArray(arr, n);
    sortedArray(arr, n);

    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the element to search for: ");
    scanf("%d", &x);

    comparisons = 0;
    int binaryResult = binarySearch(arr, n, x);
    if (binaryResult != -1)
        printf("Element found at index (Binary Search): %d\n", binaryResult);
    else
        printf("Element not found (Binary Search)\n");
    printf("Comparisons (Binary Search): %ld\n", comparisons);

    comparisons = 0;
    int ternaryResult = ternarySearch(arr, n, x);
    if (ternaryResult != -1)
        printf("Element found at index (Ternary Search): %d\n", ternaryResult);
    else
        printf("Element not found (Ternary Search)\n");
    printf("Comparisons (Ternary Search): %ld\n", comparisons);

    free(arr);
    return 0;
}