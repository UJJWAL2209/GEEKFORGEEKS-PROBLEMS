#include<bits/stdc++.h>
using namespace std;

int equilibriumPoint(int arr[], int n) {
    // Calculate the total sum of the array
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // Initialize leftSum to 0
    int leftSum = 0;

    // Iterate through the array to find the equilibrium point
    for (int i = 0; i < n; i++) {
        // Reduce totalSum by the current element
        totalSum -= arr[i];

        // Check if the leftSum is equal to the remaining sum (totalSum)
        if (leftSum == totalSum) {
            // Return the 1-based index of the equilibrium point
            return i + 1;
        }

        // Update leftSum for the next iteration
        leftSum += arr[i];
    }

    // If no equilibrium point is found, return -1
    return -1;
}

int main() {
    // Example usage
    int n1 = 5;
    int A1[] = {1, 3, 5, 2, 2};
    cout << "Output for Example 1: " << equilibriumPoint(A1, n1) << endl;

    int n2 = 1;
    int A2[] = {1};
    cout << "Output for Example 2: " << equilibriumPoint(A2, n2) << endl;

    return 0;
}
