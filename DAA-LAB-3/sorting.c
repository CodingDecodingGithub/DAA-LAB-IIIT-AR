#include <stdio.h>

void selection_sort(int A[], int n) {
    // 0-indexed C translation of the 1-indexed pseudocode
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        // Exchange elements
        int temp = A[i];
        A[i] = A[min_idx];
        A[min_idx] = temp;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int A[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");

    selection_sort(A, n);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");

    return 0;
}