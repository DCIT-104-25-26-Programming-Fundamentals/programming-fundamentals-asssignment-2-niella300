// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================












#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<double>> readMatrix(int rows, int cols);
void printMatrix(vector<vector<double>> matrix);
vector<vector<double>> transposeMatrix(vector<vector<double>> matrix);
vector<vector<double>> addMatrices(vector<vector<double>> a, vector<vector<double>> b);
vector<vector<double>> multiplyMatrices(vector<vector<double>> a, vector<vector<double>> b);
void printMenu();

int main() {
    int choice;

    while (true) {
        printMenu();
        cout << "Select an operation (1-4): ";
        cin >> choice;

        if (choice == 1) {
            // ---------------- PART A: TRANSPOSE ----------------
            int rows, cols;
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;

            vector<vector<double>> matrix = readMatrix(rows, cols);

            cout << "\nOriginal Matrix:" << endl;
            printMatrix(matrix);

            cout << "\nTransposed Matrix:" << endl;
            printMatrix(transposeMatrix(matrix));

        } else if (choice == 2) {
            // ---------------- PART B: ADDITION ----------------
            int rows, cols;
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;

            cout << "\nMatrix A:" << endl;
            vector<vector<double>> a = readMatrix(rows, cols);

            cout << "\nMatrix B (must be the same size):" << endl;
            vector<vector<double>> b = readMatrix(rows, cols);


            printMatrix(addMatrices(a, b));

        } else if (choice == 3) {
            // ---------------- PART C: MULTIPLICATION ----------------
            int m, n, n2, p;
            cout << "Matrix A dimensions:" << endl;
            cout << "Enter number of rows (M): ";
            cin >> m;
            cout << "Enter number of columns (N): ";
            cin >> n;

            cout << "\nMatrix A:" << endl;
            vector<vector<double>> a = readMatrix(m, n);

            cout << "\nMatrix B dimensions:" << endl;
            cout << "Enter number of rows (must equal N = " << n << "): ";
            cin >> n2;
            cout << "Enter number of columns (P): ";
            cin >> p;

            if (n2 != n) {
                cout << "Error: Number of columns in A must equal number of rows in B." << endl;
                continue;   // skip the rest of this loop pass, show menu again
            }

            cout << "\nMatrix B:" << endl;
            vector<vector<double>> b = readMatrix(n2, p);

            cout << "\nProduct (A x B):" << endl;
            printMatrix(multiplyMatrices(a, b));

        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;   // exits the while(true) loop
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void printMenu() {
    cout << "\n================================" << endl;
    cout << "      MATRIX OPERATIONS MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Transpose a matrix" << endl;
    cout << "2. Add two matrices" << endl;
    cout << "3. Multiply two matrices" << endl;
    cout << "4. Quit" << endl;
}

// Reads a matrix row by row. Each row's values are typed on one line,
// separated by spaces — cin >> automatically handles the spaces for us.
vector<vector<double>> readMatrix(int rows, int cols) {
    vector<vector<double>> matrix(rows, vector<double>(cols));

    for (int i = 0; i < rows; i++) {
        cout << "Enter row " << (i + 1) << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

void printMatrix(vector<vector<double>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

vector<vector<double>> transposeMatrix(vector<vector<double>> matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Transposed matrix has swapped dimensions: cols become rows
    vector<vector<double>> result(cols, vector<double>(rows));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

vector<vector<double>> addMatrices(vector<vector<double>> a, vector<vector<double>> b) {
    int rows = a.size();
    int cols = a[0].size();

    vector<vector<double>> result(rows, vector<double>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}

vector<vector<double>> multiplyMatrices(vector<vector<double>> a, vector<vector<double>> b) {
    int m = a.size();      // rows in A
    int n = a[0].size();   // cols in A / rows in B
    int p = b[0].size();   // cols in B

    vector<vector<double>> result(m, vector<double>(p, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}
