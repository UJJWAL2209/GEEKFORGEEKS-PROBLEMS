#include<bits/stdc++.h>
using namespace std;

long long maxProduct(int arr[], int n) {
    // Initialize variables to store the current maximum and minimum products
    long long max_product = arr[0];
    long long min_product = arr[0];
    long long result = arr[0];
    
    for (int i = 1; i < n; ++i) {
        // If the current element is negative, swap the maximum and minimum products
        if (arr[i] < 0) {
            swap(max_product, min_product);
        }

        // Update the maximum and minimum products for the current element
        max_product = max(static_cast<long long>(arr[i]), max_product * arr[i]);
        min_product = min(static_cast<long long>(arr[i]), min_product * arr[i]);

        // Update the overall result
        result = max(result, max_product);
    }

    return result;
}

int main() {
    // Example usage:
    int N1 = 5;
    int Arr1[] = {6, -3, -10, 0, 2};
    cout << maxProduct(Arr1, N1) << endl;  // Output: 180

    int N2 = 6;
    int Arr2[] = {2, 3, 4, 5, -1, 0};
    cout << maxProduct(Arr2, N2) << endl;  // Output: 120

    return 0;
}
