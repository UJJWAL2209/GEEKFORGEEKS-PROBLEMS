#include <iostream>
#include <vector>

using namespace std;

long long maximumSumSubarray(int K, vector<int>& Arr) {
    int N = Arr.size();
    if (N < K) {
        return -1; // Invalid input: Subarray size K exceeds array size
    }

    long long windowSum = 0;
    for (int i = 0; i < K; ++i) {
        windowSum += Arr[i]; // Calculate the initial sum of the first window of size K
    }

    long long maxSum = windowSum;
    for (int i = K; i < N; ++i) {
        windowSum += Arr[i] - Arr[i - K]; // Slide the window by adding the next element and subtracting the first element of the window
        maxSum = max(maxSum, windowSum); // Update maxSum if the current window sum is greater
    }

    return maxSum;
}

int main() {
    int N1 = 4, K1 = 2;
    vector<int> Arr1 = {100, 200, 300, 400};
    cout << maximumSumSubarray(K1, Arr1) << endl; // Output: 700

    int N2 = 4, K2 = 4;
    vector<int> Arr2 = {100, 200, 300, 400};
    cout << maximumSumSubarray(K2, Arr2) << endl; // Output: 1000

    return 0;
}
