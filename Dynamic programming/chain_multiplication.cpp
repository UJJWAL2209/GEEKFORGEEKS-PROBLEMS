#include <iostream>
#include <climits>
using namespace std;

int matrixMultiplication(int N, int arr[]) {
    // Create a 2D array to store the minimum number of multiplications
    int dp[N][N];

    // Initialize the dp array with zeros
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill the dp array using bottom-up dynamic programming
    for (int len = 2; len < N; len++) {
        for (int i = 1; i < N - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // The result is stored in dp[1][N-1]
    return dp[1][N - 1];
}

int main() {
    int N1 = 5;
    int arr1[] = {40, 20, 30, 10, 30};
    cout << "Output 1: " << matrixMultiplication(N1, arr1) << endl;

    int N2 = 4;
    int arr2[] = {10, 30, 5, 60};
    cout << "Output 2: " << matrixMultiplication(N2, arr2) << endl;

    return 0;
}
