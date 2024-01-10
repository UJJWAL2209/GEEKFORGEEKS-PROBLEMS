#include<bits/stdc++.h>
using namespace std;

int longSubarrWthSumDivByK(int arr[], int n, int k) {
    unordered_map<int, int> remainderMap; // To store the remainder and its corresponding index
    int prefixSum = 0, maxLength = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        
        // To handle negative numbers
        prefixSum = (prefixSum % k + k) % k;

        if (prefixSum == 0) {
            // If prefixSum is already divisible by k, update maxLength
            maxLength = max(maxLength, i + 1);
        } else {
            // If prefixSum is not divisible by k, check if we have seen the same remainder before
            if (remainderMap.find(prefixSum) != remainderMap.end()) {
                maxLength = max(maxLength, i - remainderMap[prefixSum]);
            } else {
                // If the remainder is encountered for the first time, store its index
                remainderMap[prefixSum] = i;
            }
        }
    }

    return maxLength;
}

int main() {
    int N, K;
    cout << "Enter the size of the array (N): ";
    cin >> N;

    int arr[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of K: ";
    cin >> K;

    int result = longSubarrWthSumDivByK(arr, N, K);
    cout << "Length of the longest subarray with sum divisible by K: " << result << endl;

    return 0;
}
