#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = 15;
    srand(time(0));
    
    FILE *fp = fopen("quick_data.txt", "w");
    for(int i=0; i<n; i++) {
        fprintf(fp, "%d ", rand() % 100);
    }
    fclose(fp);

    int arr[15];
    fp = fopen("quick_data.txt", "r");
    for(int i=0; i<n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    printf("Data from file: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    quickSort(arr, 0, n-1);
    
    printf("Quick Sorted:   ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
