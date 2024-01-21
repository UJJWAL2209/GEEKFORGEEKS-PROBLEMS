#include<bits/stdc++.h>
using namespace std;

long long trappingWater(int arr[], int n) {
    if (n <= 2) {
        return 0; // Water trapping is not possible with less than 3 blocks
    }

    long long result = 0;
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;

    while (left < right) {
        if (arr[left] < arr[right]) {
            // Update leftMax if the current block is taller
            leftMax = max(leftMax, arr[left]);
            // Calculate water trapped at the current position
            result += max(0, leftMax - arr[left]);
            left++;
        } else {
            // Update rightMax if the current block is taller
            rightMax = max(rightMax, arr[right]);
            // Calculate water trapped at the current position
            result += max(0, rightMax - arr[right]);
            right--;
        }
    }

    return result;
}

int main() {
    // Example usage
    int N1 = 6;
    int arr1[] = {3, 0, 0, 2, 0, 4};
    cout << trappingWater(arr1, N1) << endl;  // Output: 10

    int N2 = 4;
    int arr2[] = {7, 4, 0, 9};
    cout << trappingWater(arr2, N2) << endl;  // Output: 10

    int N3 = 3;
    int arr3[] = {6, 9, 9};
    cout << trappingWater(arr3, N3) << endl;  // Output: 0

    return 0;
}
