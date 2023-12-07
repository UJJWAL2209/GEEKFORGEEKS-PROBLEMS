#include <iostream>
#include <vector>

using namespace std;

int MissingNumber(vector<int>& arr, int n) {
    int total = (n * (n + 1)) / 2; // Sum of first N natural numbers
    int sum = 0;

    for (int i = 0; i < n - 1; ++i) {
        sum += arr[i];
    }

    return total - sum; // The missing number will be the difference
}

int main() {
    // Example usage
    vector<int> arr1 = {1, 2, 3, 5};
    int n1 = 5;
    cout << "Missing number: " << MissingNumber(arr1, n1) << endl;

    vector<int> arr2 = {6, 1, 2, 8, 3, 4, 7, 10, 5};
    int n2 = 10;
    cout << "Missing number: " << MissingNumber(arr2, n2) << endl;

    return 0;
}
