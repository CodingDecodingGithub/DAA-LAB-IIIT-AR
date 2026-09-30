#include <stdio.h>
int max(int a, int b) { return (a > b) ? a : b; }
int lis(int arr[], int n) {
 int dp[n];
 int max_len = 1;
 for (int i = 0; i < n; i++) dp[i] = 1;
 for (int i = 1; i < n; i++) {
 for (int j = 0; j < i; j++) {
 if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
 dp[i] = dp[j] + 1;
 }
 }
 if (dp[i] > max_len) max_len = dp[i];
 }
 return max_len;
}
int main() {
 int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
 int n = sizeof(arr) / sizeof(arr[0]);
 printf("Array: 10, 22, 9, 33, 21, 50, 41, 60\n");
 printf("Length of LIS: %d\n", lis(arr, n));
 printf("Time Complexity: O(n^2)\n");
 printf("Space Complexity: O(n)\n");
 return 0;
}
