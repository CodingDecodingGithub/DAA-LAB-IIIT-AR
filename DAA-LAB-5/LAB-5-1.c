#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r) {
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int kthSmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int index = partition(arr, l, r);
        if (index - l == k - 1)
            return arr[index];
        if (index - l > k - 1)
            return kthSmallest(arr, l, index - 1, k);
        return kthSmallest(arr, index + 1, r, k - index + l - 1);
    }
    return -1;
}

double findMedian(int arr[], int n) {
    if (n % 2 != 0)
        return (double)kthSmallest(arr, 0, n - 1, n / 2 + 1);
    else {
        int mid1 = kthSmallest(arr, 0, n - 1, n / 2);
        int mid2 = kthSmallest(arr, 0, n - 1, n / 2 + 1);
        return (mid1 + mid2) / 2.0;
    }
}

int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    printf("Median is %.1f\n", findMedian(arr, n));
    
    printf("\nComplexity Analysis:\n");
    printf("Time Complexity: O(N) on average, O(N^2) in worst case.\n");
    printf("Space Complexity: O(1) auxiliary space.\n");
    return 0;
}
