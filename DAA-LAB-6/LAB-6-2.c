#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N 3

// (i) Matrix Addition - O(n^2)
void add_matrices(double A[N][N], double B[N][N], double C[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// (ii) Matrix Multiplication - O(n^3)
void multiply_matrices(double A[N][N], double B[N][N], double C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// (iii) Zero Matrix Check - O(n^2)
bool is_zero_matrix(double A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] != 0.0) return false;
        }
    }
    return true;
}

// (iv) Symmetric Matrix Check - O(n^2)
bool is_symmetric(double A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i][j] != A[j][i]) return false;
        }
    }
    return true;
}

// (v) Determinant (using simple Gaussian Elimination) - O(n^3)
double determinant(double matrix[N][N]) {
    double mat[N][N];
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) mat[i][j] = matrix[i][j];
    
    double det = 1.0;
    for (int i = 0; i < N; i++) {
        if (mat[i][i] == 0) return 0.0; // Simplified for basic validation
        for (int j = i + 1; j < N; j++) {
            double ratio = mat[j][i] / mat[i][i];
            for (int k = i; k < N; k++) {
                mat[j][k] -= ratio * mat[i][k];
            }
        }
        det *= mat[i][i];
    }
    return det;
}

// (vi) Transpose In Situ - O(n^2)
void transpose_in_place(double A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

// (vii) Dominant Eigenvalue using Power Iteration - O(n^2) per iteration
double power_iteration(double A[N][N], double vec[N], int iterations) {
    double temp[N];
    double eigenvalue = 0;
    
    for (int iter = 0; iter < iterations; iter++) {
        // Matrix-vector multiplication
        for (int i = 0; i < N; i++) {
            temp[i] = 0;
            for (int j = 0; j < N; j++) temp[i] += A[i][j] * vec[j];
        }
        
        // Find max element for normalization
        double max_val = fabs(temp[0]);
        for (int i = 1; i < N; i++) {
            if (fabs(temp[i]) > max_val) max_val = fabs(temp[i]);
        }
        eigenvalue = max_val;
        
        // Normalize vector
        for (int i = 0; i < N; i++) vec[i] = temp[i] / max_val;
    }
    return eigenvalue;
}

int main() {
    double A[N][N] = {{4, 1, 1}, {1, 3, 2}, {1, 2, 5}};
    double B[N][N] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double C[N][N];

    printf("Is A symmetric? %s\n", is_symmetric(A) ? "Yes" : "No");
    printf("Is A a zero matrix? %s\n", is_zero_matrix(A) ? "Yes" : "No");
    
    printf("Determinant of A: %.2f\n", determinant(A));
    
    double vec[N] = {1, 1, 1};
    double eigenval = power_iteration(A, vec, 20);
    printf("Dominant Eigenvalue of A: %.2f\n", eigenval);
    
    transpose_in_place(A);
    printf("A[0][1] after transpose: %.2f\n", A[0][1]);

    return 0;
}