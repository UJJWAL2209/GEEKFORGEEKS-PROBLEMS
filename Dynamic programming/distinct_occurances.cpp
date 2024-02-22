#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int subsequenceCount(string s, string t) {
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize base cases
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (s[i - 1] == t[j - 1])
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
        }
    }

    return dp[n][m];
}

int main() {
    string s1 = "banana", t1 = "ban";
    cout << subsequenceCount(s1, t1) << endl;  // Output: 3

    string s2 = "geeksforgeeks", t2 = "ge";
    cout << subsequenceCount(s2, t2) << endl;  // Output: 6

    return 0;
}
