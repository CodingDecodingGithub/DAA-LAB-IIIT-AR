#include <stdio.h>
#include <limits.h>

int max(int a, int b) { return (a > b) ? a : b; }

int superEggDrop(int E, int F) {
    int dp[E + 1][F + 1];
    for (int i = 1; i <= E; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int j = 1; j <= F; j++) {
        dp[1][j] = j;
    }
    for (int i = 2; i <= E; i++) {
        for (int j = 2; j <= F; j++) {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++) {
                int res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                if (res < dp[i][j]) {
                    dp[i][j] = res;
                }
            }
        }
    }
    return dp[E][F];
}

int main() {
    int eggs = 2, floors = 100;
    printf("Eggs: %d, Floors: %d\n", eggs, floors);
    printf("Minimum number of droppings: %d\n", superEggDrop(eggs, floors));
    printf("Time Complexity: O(E * F^2)\n");
    printf("Space Complexity: O(E * F)\n");
    return 0;
}