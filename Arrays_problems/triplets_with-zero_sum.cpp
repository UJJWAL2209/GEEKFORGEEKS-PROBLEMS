#include <iostream>
#include <algorithm>
using namespace std;

bool findTriplets(int arr[], int n) {
    sort(arr, arr + n); // Sort the array

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;
        int target = -arr[i]; // We want a sum of zero, so the third element should be the negative of the first two.

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target) {
                return true; // Triplet found
            } else if (sum < target) {
                ++left; // Move left pointer to increase sum
            } else {
                --right; // Move right pointer to decrease sum
            }
        }
    }

    return false; // No triplet found
}

int main() {
    int n1 = 5;
    int arr1[] = {0, -1, 2, -3, 1};
    cout << findTriplets(arr1, n1) << endl; // Output: 1

    int n2 = 3;
    int arr2[] = {1, 2, 3};
    cout << findTriplets(arr2, n2) << endl; // Output: 0

    return 0;
}
