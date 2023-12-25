#include <iostream>
#include <vector>

using namespace std;

#define MAX 10

// Function to calculate the determinant of a matrix
int determinantOfMatrix(vector<vector<int>> mat, int n) {
    // Base case: If the matrix is of size 1x1, return the element
    if (n == 1) {
        return mat[0][0];
    }

    int det = 0; // Initialize result

    // Iterate through each element of the first row
    for (int i = 0; i < n; i++) {
        // Calculate the cofactor of mat[0][i]
        vector<vector<int>> tempMat(n - 1, vector<int>(n - 1));
        int sign = (i % 2 == 0) ? 1 : -1; // Sign changes for each alternate element
        int temp_i = 0, temp_j = 0;

        // Form the matrix without the current row and column
        for (int row = 1; row < n; row++) {
            temp_j = 0;
            for (int col = 0; col < n; col++) {
                if (col != i) {
                    tempMat[temp_i][temp_j] = mat[row][col];
                    temp_j++;
                }
            }
            temp_i++;
        }

        // Recursive call to calculate the determinant of the submatrix
        det += sign * mat[0][i] * determinantOfMatrix(tempMat, n - 1);
    }

    return det;
}

int main() {
    int n;
    cout << "Enter the size of the matrix (1 <= N <= 10): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = determinantOfMatrix(matrix, n);
    cout << "Determinant of the given matrix is: " << result << endl;

    return 0;
}
