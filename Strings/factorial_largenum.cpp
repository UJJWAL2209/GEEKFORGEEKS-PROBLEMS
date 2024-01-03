#include <iostream>
#include <vector>
#include<bits/stdtr1c++.h>

using namespace std;

vector<int> factorial(int N) {
    vector<int> result;
    result.push_back(1); // Initialize the result with 1

    for (int i = 2; i <= N; ++i) {
        int carry = 0;

        // Multiply each digit of the result by i
        for (int j = 0; j < result.size(); ++j) {
            int product = result[j] * i + carry;
            result[j] = product % 10;
            carry = product / 10;
        }

        // Add the remaining carry digits
        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    int N = 5;
    vector<int> result = factorial(N);

    cout << "Input: " << N << "\nOutput: ";
    for (int digit : result) {
        cout << digit;
    }
    cout << "\n";

    return 0;
}
