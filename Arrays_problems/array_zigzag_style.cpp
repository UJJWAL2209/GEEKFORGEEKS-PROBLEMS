#include <iostream>
#include <vector>

using namespace std;

void zigZag(vector<int> &arr, int n) {
    // Flag to determine whether the current element should be lesser or greater
    bool less = true;

    for (int i = 0; i < n - 1; ++i) {
        if (less) {
            // If the current element should be lesser, check if it's greater than the next element
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        } else {
            // If the current element should be greater, check if it's lesser than the next element
            if (arr[i] < arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
        // Invert the flag for the next iteration
        less = !less;
    }
}

int main() {
    // Example usage
    vector<int> arr1 = {4, 3, 7, 8, 6, 2, 1};
    int n1 = arr1.size();
    zigZag(arr1, n1);
    for (int i = 0; i < n1; ++i) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    vector<int> arr2 = {1, 4, 3, 2};
    int n2 = arr2.size();
    zigZag(arr2, n2);
    for (int i = 0; i < n2; ++i) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
