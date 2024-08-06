#include <iostream>

using namespace std;

// Function to print the 2D array in spiral order
void spiralPrint(int **input, int nRows, int nCols) {
    int startRow = 0, endRow = nRows - 1;
    int startCol = 0, endCol = nCols - 1;

    while (startRow <= endRow && startCol <= endCol) {
        // Print the top row
        for (int i = startCol; i <= endCol; i++) {
            cout << input[startRow][i] << " ";
        }
        startRow++;

        // Print the rightmost column
        for (int i = startRow; i <= endRow; i++) {
            cout << input[i][endCol] << " ";
        }
        endCol--;

        // Print the bottom row if there are still rows left
        if (startRow <= endRow) {
            for (int i = endCol; i >= startCol; i--) {
                cout << input[endRow][i] << " ";
            }
            endRow--;
        }

        // Print the leftmost column if there are still columns left
        if (startCol <= endCol) {
            for (int i = endRow; i >= startRow; i--) {
                cout << input[i][startCol] << " ";
            }
            startCol++;
        }
    }
    cout << endl; // Print a newline at the end
}

int main() {
    int nRows, nCols;
    cout << "Enter the number of rows: ";
    cin >> nRows;
    cout << "Enter the number of columns: ";
    cin >> nCols;

    // Dynamically allocate 2D array
    int **input = new int*[nRows];
    for (int i = 0; i < nRows; i++) {
        input[i] = new int[nCols];
    }

    // Input the elements of the 2D array
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            cin >> input[i][j];
        }
    }

    // Print the matrix in spiral order
    spiralPrint(input, nRows, nCols);

    // Deallocate memory
    for (int i = 0; i < nRows; i++) {
        delete[] input[i];
    }
    delete[] input;

    return 0;
}
