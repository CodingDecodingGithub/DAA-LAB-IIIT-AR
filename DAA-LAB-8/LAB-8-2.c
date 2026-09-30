#include <stdio.h>
int countWays(int coins[], int n, int V) {
 int dp[V + 1];
 for (int i = 0; i <= V; i++) dp[i] = 0;
 dp[0] = 1;
 for (int i = 0; i < n; i++) {
 for (int j = coins[i]; j <= V; j++) {
 dp[j] += dp[j - coins[i]];
 }
 }
 return dp[V];
}
int main() {
 int coins[] = {1, 2, 5};
 int n = sizeof(coins) / sizeof(coins[0]);
 int V = 5;
 printf("Coins: 1, 2, 5 | Target: %d\n", V);
 printf("Total number of distinct combinations: %d\n", countWays(coins, n, V));
 printf("Time Complexity: O(n*V)\n");
 printf("Space Complexity: O(V)\n");
 return 0;
}
