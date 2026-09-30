#include <stdio.h>
#include <string.h>
int max(int a, int b) { return (a > b) ? a : b; }
void lcs(char *X, char *Y, int m, int n) {
 int dp[m + 1][n + 1];
 for (int i = 0; i <= m; i++) {
 for (int j = 0; j <= n; j++) {
 if (i == 0 || j == 0)
 dp[i][j] = 0;
 else if (X[i - 1] == Y[j - 1])
 dp[i][j] = dp[i - 1][j - 1] + 1;
 else
 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
 }
 }
 int index = dp[m][n];
 char lcsStr[index + 1];
 lcsStr[index] = '\0';
 int i = m, j = n;
 while (i > 0 && j > 0) {
 if (X[i - 1] == Y[j - 1]) {
 lcsStr[index - 1] = X[i - 1];
 i--; j--; index--;
 } else if (dp[i - 1][j] > dp[i][j - 1]) {
 i--;
 } else {
 j--;
 }
 }
 printf("LCS Length: %d\n", dp[m][n]);
 printf("LCS String: %s\n", lcsStr);
}
int main() {
 char X[] = "AGGTAB";
 char Y[] = "GXTXAYB";
 int m = strlen(X);
 int n = strlen(Y);
 printf("String X: %s\nString Y: %s\n", X, Y);
 lcs(X, Y, m, n);
 printf("Time Complexity: O(m*n)\n");
 printf("Space Complexity: O(m*n)\n");
 return 0;
}