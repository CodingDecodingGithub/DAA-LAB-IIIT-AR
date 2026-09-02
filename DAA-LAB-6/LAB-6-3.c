#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define PI 3.14159265358979323846

// Recursive FFT (Divide and Conquer)
void fft(double complex *a, int n) {
    if (n <= 1) return;

    // Divide
    double complex *even = malloc(n / 2 * sizeof(double complex));
    double complex *odd  = malloc(n / 2 * sizeof(double complex));
    for (int i = 0; i < n / 2; i++) {
        even[i] = a[2 * i];
        odd[i]  = a[2 * i + 1];
    }

    // Conquer
    fft(even, n / 2);
    fft(odd, n / 2);

    // Combine
    for (int i = 0; i < n / 2; i++) {
        double complex t = cexp(-I * 2 * PI * i / n) * odd[i];
        a[i] = even[i] + t;
        a[i + n / 2] = even[i] - t;
    }

    free(even);
    free(odd);
}

// Inverse FFT
void ifft(double complex *a, int n) {
    for (int i = 0; i < n; i++) a[i] = conj(a[i]);
    fft(a, n);
    for (int i = 0; i < n; i++) a[i] = conj(a[i]) / n;
}

// Helper to get next power of 2
int next_power_of_2(int x) {
    int power = 1;
    while (power < x) power *= 2;
    return power;
}

int main() {
    // Example vectors
    double A_input[] = {1, 2, 3}; // Length m = 3
    double B_input[] = {4, 5, 6, 7}; // Length n = 4
    int m = 3;
    int n = 4;
    
    int result_len = n + m - 1;
    int N = next_power_of_2(result_len);

    // Initialize padded arrays with complex zeros
    double complex *A = calloc(N, sizeof(double complex));
    double complex *B = calloc(N, sizeof(double complex));

    for (int i = 0; i < m; i++) A[i] = A_input[i];
    for (int i = 0; i < n; i++) B[i] = B_input[i];

    // O(N log N) Transformations
    fft(A, N);
    fft(B, N);

    // O(N) Point-wise multiplication
    double complex *C = calloc(N, sizeof(double complex));
    for (int i = 0; i < N; i++) {
        C[i] = A[i] * B[i];
    }

    // O(N log N) Inverse Transformation
    ifft(C, N);

    // Print result (extracting real parts)
    printf("Convolution Result: ");
    for (int i = 0; i < result_len; i++) {
        printf("%.1f ", creal(C[i]));
    }
    printf("\n");

    free(A); free(B); free(C);
    return 0;
}