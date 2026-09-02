#include <stdio.h>
#include <stdlib.h>

int total_cost = 0;

// Reverses the subarray p[i...j] and adds its length to total_cost
void reverse(int p[], int i, int j) {
    if (i >= j) return;
    total_cost += (j - i + 1);
    while (i < j) {
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        i++;
        j--;
    }
}

// Finds the first index in p[left...right] where the element is >= val
int binary_search(int p[], int left, int right, int val) {
    int ans = right + 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (p[mid] >= val) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

// Merges two adjacent sorted subarrays p[left...mid] and p[mid+1...right]
void merge(int p[], int left, int mid, int right) {
    // FIX: Prevents infinite recursion on already-sorted contiguous blocks
    if (p[mid] <= p[mid + 1]) return; 

    int lenL = mid - left + 1;
    int lenR = right - mid;
    if (lenL <= 0 || lenR <= 0) return;

    int cutL, cutR;
    
    // Pick the median of the larger subarray as the pivot
    if (lenL >= lenR) {
        cutL = left + lenL / 2;
        cutR = binary_search(p, mid + 1, right, p[cutL]);
    } else {
        cutR = mid + 1 + lenR / 2;
        cutL = binary_search(p, left, mid, p[cutR]);
    }

    int L1_len = cutL - left;
    int L2_len = mid - cutL + 1;
    int R1_len = cutR - (mid + 1);
    
    // Block swap L2 and R1
    reverse(p, cutL, mid);
    reverse(p, mid + 1, cutR - 1);
    reverse(p, cutL, cutR - 1);

    int left_end = left + L1_len + R1_len - 1;
    int new_mid_left = left + L1_len - 1;
    int new_mid_right = left_end + L2_len; 
    
    // Recursively merge the generated subpartitions
    merge(p, left, new_mid_left, left_end);
    merge(p, left_end + 1, new_mid_right, right);
}

void merge_sort_reversals(int p[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort_reversals(p, left, mid);
    merge_sort_reversals(p, mid + 1, right);
    merge(p, left, mid, right);
}

int main() {
    int p[] = {1, 4, 3, 2, 5, 9, 8, 7, 6, 10};
    int n = sizeof(p) / sizeof(p[0]);
    
    merge_sort_reversals(p, 0, n - 1);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\nTotal Cost (sum of reversed lengths): %d\n", total_cost);
    
    return 0;
}