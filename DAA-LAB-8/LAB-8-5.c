#include <stdio.h>
#include <stdlib.h>

int main(void) {
 int n;
 printf("Enter n: ");
 if (scanf("%d", &n) != 1 || n <= 0) {
 printf("Invalid n\n");
 return 1;
 }
 int *A = malloc(n * sizeof(int));
 long long *dp = malloc(n * sizeof(long long));
 int *prev = malloc(n * sizeof(int));
 int *seq = malloc(n * sizeof(int));
 printf("Enter %d positive integers: ", n);
 for (int i = 0; i < n; i++) scanf("%d", &A[i]);
 int best = 0;
 for (int i = 0; i < n; i++) {
 dp[i] = A[i];
 prev[i] = -1;
 for (int j = 0; j < i; j++) {
 if (A[j] < A[i] && dp[j] + A[i] > dp[i]) {
 dp[i] = dp[j] + A[i];
 prev[i] = j;
 }
 }
 if (dp[i] > dp[best]) best = i;
 }
 printf("Maximum sum = %lld\n", dp[best]);
 int len = 0;
 for (int k = best; k != -1; k = prev[k]) seq[len++] = A[k];
 printf("Subsequence: ");
 for (int k = len - 1; k >= 0; k--) printf("%d ", seq[k]);
 printf("\n");
 free(A); free(dp); free(prev); free(seq);
 return 0;
}