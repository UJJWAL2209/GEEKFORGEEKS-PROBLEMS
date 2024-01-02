#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int nCr(int n, int r) {
    if (r > n) {
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= min(i, r); ++j) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
    }

    return dp[n][r];
}

int main() {
    int n1 = 3, r1 = 2;
    cout << nCr(n1, r1) << endl;  // Output: 3

    int n2 = 2, r2 = 4;
    cout << nCr(n2, r2) << endl;  // Output: 0

    return 0;
}
