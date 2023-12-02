#include <iostream>
using namespace std;

void convertToWave(int *arr, int n) {
    for (int i = 0; i < n - 1; i += 2) {
        // Swap adjacent elements in pairs
        if (i > 0 && arr[i - 1] > arr[i]) {
            swap(arr[i - 1], arr[i]);
        }
        if (i < n - 1 && arr[i] < arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
}

// Example usage
int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    convertToWave(arr1, n1);
    cout << "Wave array 1: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    int arr2[] = {2, 4, 7, 8, 9, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    convertToWave(arr2, n2);
    cout << "Wave array 2: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}