#include<bits/stdc++.h>
using namespace std;

// Function to calculate the prime factorization of a number
vector<pair<int, int>> primeFactorization(int n) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            factors.push_back({i, count});
        }
    }
    if (n > 1) {
        factors.push_back({n, 1});
    }
    return factors;
}

// Function to calculate the sum of powers of primes between a and b (inclusive)
int sumOfPowers(int a, int b) {
    int sum = 0;
    for (int i = a; i <= b; ++i) {
        vector<pair<int, int>> factors = primeFactorization(i);
        for (auto factor : factors) {
            sum += factor.second;
        }
    }
    return sum;
}

int main() {
    // Example usage:
    int a1 = 9, b1 = 12;
    cout << sumOfPowers(a1, b1) << endl; // Output: 8

    int a2 = 24, b2 = 27;
    cout << sumOfPowers(a2, b2) << endl; // Output: 11

    return 0;
}
