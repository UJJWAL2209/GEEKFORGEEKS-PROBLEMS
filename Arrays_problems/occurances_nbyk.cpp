#include<bits/stdc++.h>
using namespace std;

int countOccurrence(int arr[], int n, int k) {
    unordered_map<int, int> freqMap;

    for (int i = 0; i < n; i++) {
        freqMap[arr[i]]++;
    }

    int count = 0;

    for (auto it : freqMap) {
        if (it.second > n / k) {
            count++;
        }
    }

    return count;
}

int main() {
    int N1 = 8;
    int arr1[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int k1 = 4;

    cout << "Output for Example 1: " << countOccurrence(arr1, N1, k1) << endl;

    int N2 = 4;
    int arr2[] = {2, 3, 3, 2};
    int k2 = 3;

    cout << "Output for Example 2: " << countOccurrence(arr2, N2, k2) << endl;

    return 0;
}
