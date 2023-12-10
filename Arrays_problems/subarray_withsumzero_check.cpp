#include <iostream>
#include <unordered_set>
using namespace std;

bool subArrayExists(int arr[], int n) {
    unordered_set<int> prefixSums;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If the current prefix sum is 0 or it's already present in the set,
        // there exists a subarray with a sum of 0.
        if (sum == 0 || prefixSums.find(sum) != prefixSums.end())
            return true;

        // Add the current prefix sum to the set
        prefixSums.insert(sum);
    }

    // No subarray with sum 0 found
    return false;
}

int main() {
    int n1 = 5;
    int arr1[] = {4, 2, -3, 1, 6};
    cout << (subArrayExists(arr1, n1) ? "Yes" : "No") << endl;

    int n2 = 5;
    int arr2[] = {4, 2, 0, 1, 6};
    cout << (subArrayExists(arr2, n2) ? "Yes" : "No") << endl;

    return 0;
}
