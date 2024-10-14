#include <stdio.h>

#define SIZE 5  // Define the size of the matrix (5x5 matrix)

// Function to print a matrix
void printMatrix(int matrix[SIZE][SIZE]) {
    // Loop through each row and column to print the matrix in a grid format
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", matrix[i][j]);  // Print each element with a tab for formatting
        }
        printf("\n");  // Move to the next line after printing one row
    }
}

// Function to add two matrices and store the result in a third matrix
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Loop through each element in the matrices
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Add corresponding elements from m1 and m2, store in result
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Function to multiply two matrices and store the result in a third matrix
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Initialize result matrix to 0
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
        }
    }

    // Loop through rows of m1 and columns of m2
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// Function to transpose a matrix (swap rows and columns)
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Loop through each element, swap row and column
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];  // Transpose by swapping indices
        }
    }
}

int main() {
    // Define two sample matrices (m1 and m2) as given in the lab description
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    // Declare matrices to hold results
    int result[SIZE][SIZE];  // For storing results of addition, multiplication, and transpose
    int transpose[SIZE][SIZE];  // For storing transpose of a matrix

    // Display the first matrix
    printf("Matrix 1:\n");
    printMatrix(m1);

    // Display the second matrix
    printf("\nMatrix 2:\n");
    printMatrix(m2);

    // Perform matrix addition
    addMatrices(m1, m2, result);
    printf("\nSum of Matrix 1 and Matrix 2:\n");
    printMatrix(result);  // Print the result of matrix addition

    // Perform matrix multiplication
    multiplyMatrices(m1, m2, result);
    printf("\nProduct of Matrix 1 and Matrix 2:\n");
    printMatrix(result);  // Print the result of matrix multiplication

    // Transpose the first matrix
    transposeMatrix(m1, transpose);
    printf("\nTranspose of Matrix 1:\n");
    printMatrix(transpose);  // Print the transpose of the first matrix

    return 0;
}
