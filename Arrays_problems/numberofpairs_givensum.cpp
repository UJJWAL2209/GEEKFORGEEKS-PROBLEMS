#include<bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k) {
    unordered_map<int, int> freqMap;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int complement = k - arr[i];

        // Check if complement is present in the map
        if (freqMap.find(complement) != freqMap.end()) {
            count += freqMap[complement];
        }

        // Increment the frequency of the current element in the map
        freqMap[arr[i]]++;
    }

    return count;
}

int main() {
    int N, K;
    cout << "Enter the size of the array: ";
    cin >> N;

    int arr[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of K: ";
    cin >> K;

    int result = getPairsCount(arr, N, K);
    cout << "Number of pairs with sum " << K << " is: " << result << endl;

    return 0;
}
