#include <iostream>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N; // Read the dimensions of the matrix

    int matrix[1000][1000]; // Declare a 2D array for the matrix
    int columnSum[1000] = {0}; // Array to hold the sum of each column, initialized to 0

    // Read the matrix elements
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    // Calculate the sum of each column
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            columnSum[j] += matrix[i][j];
        }
    }

    // Print the column sums separated by spaces
    for (int j = 0; j < N; j++) {
        cout << columnSum[j];
        if (j < N - 1) {
            cout << " "; // Add space between sums except after the last sum
        }
    }

    return 0;
}
