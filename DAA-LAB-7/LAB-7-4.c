#include <stdio.h>

int moves = 0;

void turnOn(int n);
void turnOff(int n);

void turnOff(int n) {
    if (n == 0) return;
    if (n == 1) {
        moves++;
        return;
    }
    turnOff(n - 2);
    moves++;
    turnOn(n - 2);
    turnOff(n - 1);
}

void turnOn(int n) {
    if (n == 0) return;
    if (n == 1) {
        moves++;
        return;
    }
    turnOn(n - 1);
    turnOff(n - 2);
    moves++;
    turnOn(n - 2);
}

int main() {
    int n = 4;
    turnOff(n);
    printf("Number of switches: %d\n", n);
    printf("Minimum moves to turn all off: %d\n", moves);
    printf("Time Complexity: O(2^n)\n");
    printf("Space Complexity: O(n)\n");
    return 0;
}