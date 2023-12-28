#include <iostream>
#include <unordered_map>

using namespace std;

int firstRepeatingElement(int arr[], int n) {
    unordered_map<int, int> indexMap;

    int firstIndex = n + 1;  // Initialize with a value greater than n

    for (int i = 0; i < n; ++i) {
        if (indexMap.find(arr[i]) != indexMap.end()) {
            // If the element is already present in the map, update the first occurrence index
            firstIndex = min(firstIndex, indexMap[arr[i]]);
        } else {
            // Otherwise, store the current index as the first occurrence index
            indexMap[arr[i]] = i + 1;  // 1-based indexing
        }
    }

    // If firstIndex is still greater than n, no repeating element was found
    return (firstIndex > n) ? -1 : firstIndex;
}

int main() {
    // Test cases
    int arr1[] = {1, 5, 3, 4, 3, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << firstRepeatingElement(arr1, n1) << endl;

    int arr2[] = {1, 2, 3, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << firstRepeatingElement(arr2, n2) << endl;

    return 0;
}
