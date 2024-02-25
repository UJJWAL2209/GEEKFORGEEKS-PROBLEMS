#include <iostream>
#include <vector>
using namespace std;

long long int count(long long int n) {
    vector<long long int> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int i = 3; i <= n; i++) {
        dp[i] += dp[i - 3];
    }
    for (int i = 5; i <= n; i++) {
        dp[i] += dp[i - 5];
    }
    for (int i = 10; i <= n; i++) {
        dp[i] += dp[i - 10];
    }
    return dp[n];
}

int main() {
    // Example usage:
    long long int n1 = 10;
    cout << "Number of distinct combinations for score " << n1 << ": " << count(n1) << endl;
    
    long long int n2 = 20;
    cout << "Number of distinct combinations for score " << n2 << ": " << count(n2) << endl;
    
    return 0;
}
