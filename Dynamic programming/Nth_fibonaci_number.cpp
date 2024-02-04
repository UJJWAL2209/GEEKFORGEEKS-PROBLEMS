#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int nthFibonacci(int n) {
    if (n <= 2) {
        return 1;
    }

    vector<int> dp(n + 1);
    dp[1] = dp[2] = 1;

    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    return dp[n];
}

int main() {
    // Example 1
    int n1 = 2;
    cout << nthFibonacci(n1) << endl; // Output: 1

    // Example 2
    int n2 = 5;
    cout << nthFibonacci(n2) << endl; // Output: 5

    return 0;
}
