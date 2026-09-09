#include <stdio.h>
#include <math.h>
#include <limits.h>

int revesPuzzle(int n) {
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = INT_MAX;
        for (int k = 1; k < i; k++) {
            int moves = 2 * dp[k] + (int)pow(2, i - k) - 1;
            if (moves < dp[i]) {
                dp[i] = moves;
            }
        }
    }
    return dp[n];
}

int main() {
    int n = 8;
    printf("Number of disks: %d\n", n);
    printf("Minimum moves for %d disks (4 pegs): %d\n", n, revesPuzzle(n));
    printf("Time Complexity: O(n^2)\n");
    printf("Space Complexity: O(n)\n");
    return 0;
}