#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n = 15;
    srand(time(0));
    
    FILE *fp = fopen("heap_data.txt", "w");
    for(int i=0; i<n; i++) {
        fprintf(fp, "%d ", rand() % 100);
    }
    fclose(fp);

    int arr[15];
    fp = fopen("heap_data.txt", "r");
    for(int i=0; i<n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    printf("Data from file: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    heapSort(arr, n);
    
    printf("Heap Sorted:    ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("\nComplexity Analysis:\n");
    printf("Time Complexity: O(N log N) in all cases (best, average, worst).\n");
    printf("Space Complexity: O(1) auxiliary space.\n");

    return 0;
}
