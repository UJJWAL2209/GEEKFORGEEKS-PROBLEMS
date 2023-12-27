#include <iostream>
#include <vector>

using namespace std;

vector<int> antiDiagonalPattern(vector<vector<int>>& matrix) {
    vector<int> result;
    int N = matrix.size();

    for (int d = 0; d < 2 * N - 1; d++) {
        if (d < N) {
            for (int i = 0; i <= d; i++) {
                int j = d - i;
                result.push_back(matrix[i][j]);
            }
        } else {
            for (int i = d - N + 1; i < N; i++) {
                int j = d - i;
                result.push_back(matrix[i][j]);
            }
        }
    }

    return result;
}

int main() {
    int N;
    cout << "Enter the size of the matrix (N): ";
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N, 0));
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Enter matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    vector<int> result = antiDiagonalPattern(matrix);

    cout << "Output: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
