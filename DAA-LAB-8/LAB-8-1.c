#include <stdio.h>
#include <limits.h>
int minCoins(int coins[], int n, int V) {
 int dp[V + 1];
 dp[0] = 0;
 for (int i = 1; i <= V; i++) {
 dp[i] = INT_MAX;
 }
 for (int i = 1; i <= V; i++) {
 for (int j = 0; j < n; j++) {
 if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
 if (dp[i - coins[j]] + 1 < dp[i]) {
 dp[i] = dp[i - coins[j]] + 1;
 }
 }
 }
 }
 return dp[V] == INT_MAX ? -1 : dp[V];
}
int main() {
 int coins[] = {1, 2, 5};
 int n = sizeof(coins) / sizeof(coins[0]);
 int V = 11;
 printf("Coins: 1, 2, 5 | Target: %d\n", V);
 printf("Minimum coins needed: %d\n", minCoins(coins, n, V));
 printf("Time Complexity: O(n*V)\n");
 printf("Space Complexity: O(V)\n");
 return 0;
}