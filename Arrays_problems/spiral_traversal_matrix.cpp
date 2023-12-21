#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) {
    vector<int> result;
    int top = 0, bottom = r - 1, left = 0, right = c - 1;

    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int i = left; i <= right; ++i) {
            result.push_back(matrix[top][i]);
        }
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; ++i) {
            result.push_back(matrix[i][right]);
        }
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return result;
}

int main() {
    // Example 1
    vector<vector<int>> matrix1 = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    int r1 = 4, c1 = 4;

    vector<int> result1 = spirallyTraverse(matrix1, r1, c1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<vector<int>> matrix2 = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12}};
    int r2 = 3, c2 = 4;

    vector<int> result2 = spirallyTraverse(matrix2, r2, c2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
