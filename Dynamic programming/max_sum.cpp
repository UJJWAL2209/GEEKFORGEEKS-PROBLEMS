#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxSum(int n) {
    vector<long long> memo(n + 1);
    memo[0] = 0;

    for (int i = 1; i <= n; ++i) {
        long long sum = memo[i / 2] + memo[i / 3] + memo[i / 4];
        memo[i] = max((long long)i, sum);
    }

    return memo[n];
}

int main() {
    int n = 12;
    cout << maxSum(n) << endl; // Output: 13

    n = 24;
    cout << maxSum(n) << endl; // Output: 27

    return 0;
}
