#include <stdio.h>

// Minimum moves to invert a coin triangle of n rows
int min_moves_to_invert(int n) {
    return (n * (n + 1)) / 6;
}

int main() {
    int n = 4;
    printf("Rows: %d\n", n);
    printf("Minimum moves to invert: %d\n", min_moves_to_invert(n));
    printf("Time Complexity: O(1)\n");
    printf("Space Complexity: O(1)\n");
    return 0;
}