#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Helper function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// (i) Maximum element - O(n)
int find_max(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

// (ii) First and second largest - O(n)
void find_first_second_max(int arr[], int n, int *max1, int *max2) {
    *max1 = arr[0];
    *max2 = -2147483648; // INT_MIN
    for(int i = 1; i < n; i++) {
        if(arr[i] > *max1) {
            *max2 = *max1;
            *max1 = arr[i];
        } else if(arr[i] > *max2 && arr[i] != *max1) {
            *max2 = arr[i];
        }
    }
}

// (iii) Mean - O(n)
double find_mean(int arr[], int n) {
    double sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    return sum / n;
}

// (iv) Median (using sort for practical C implementation) - O(n log n)
double find_median(int arr[], int n) {
    int *temp = malloc(n * sizeof(int));
    for(int i=0; i<n; i++) temp[i] = arr[i];
    qsort(temp, n, sizeof(int), compare);
    
    double median;
    if (n % 2 == 0) median = (temp[n/2 - 1] + temp[n/2]) / 2.0;
    else median = temp[n/2];
    
    free(temp);
    return median;
}

// (v) Standard Deviation - O(n)
double find_std_dev(int arr[], int n) {
    double mean = find_mean(arr, n);
    double sum_sq_diff = 0;
    for(int i = 0; i < n; i++) {
        sum_sq_diff += (arr[i] - mean) * (arr[i] - mean);
    }
    return sqrt(sum_sq_diff / n);
}

// (vi) Mode (using sort) - O(n log n)
int find_mode(int arr[], int n) {
    int *temp = malloc(n * sizeof(int));
    for(int i=0; i<n; i++) temp[i] = arr[i];
    qsort(temp, n, sizeof(int), compare);
    
    int mode = temp[0], max_count = 1, current_count = 1;
    for(int i = 1; i < n; i++) {
        if(temp[i] == temp[i-1]) current_count++;
        else current_count = 1;
        
        if(current_count > max_count) {
            max_count = current_count;
            mode = temp[i];
        }
    }
    free(temp);
    return mode;
}

// (vii) Remove Duplicates (modifies array in place after sorting) - O(n log n)
int remove_duplicates(int arr[], int n) {
    if (n == 0 || n == 1) return n;
    qsort(arr, n, sizeof(int), compare);
    
    int j = 0;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] != arr[i+1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n-1];
    return j; // Returns new size
}

// (viii) Reverse Array - O(n)
void reverse_array(int arr[], int n) {
    for(int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

// (ix) Partition Array (>= pivot on left, < pivot on right) - O(n)
void partition_array(int arr[], int n, int pivot) {
    int left_idx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= pivot) {
            int temp = arr[left_idx];
            arr[left_idx] = arr[i];
            arr[i] = temp;
            left_idx++;
        }
    }
}

int main() {
    int arr[] = {4, 7, 2, 8, 4, 9, 1, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Max: %d\n", find_max(arr, n));
    
    int max1, max2;
    find_first_second_max(arr, n, &max1, &max2);
    printf("1st Max: %d, 2nd Max: %d\n", max1, max2);
    
    printf("Mean: %.2f\n", find_mean(arr, n));
    printf("Median: %.2f\n", find_median(arr, n));
    printf("Std Dev: %.2f\n", find_std_dev(arr, n));
    printf("Mode: %d\n", find_mode(arr, n));
    
    partition_array(arr, n, 5);
    printf("Partitioned (pivot 5): ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    reverse_array(arr, n);
    printf("Reversed: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    int new_n = remove_duplicates(arr, n);
    printf("Unique Elements: ");
    for(int i=0; i<new_n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}