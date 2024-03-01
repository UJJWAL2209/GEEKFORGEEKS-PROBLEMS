#include <iostream>

// Function declaration
int peakElement(int arr[], int n);

int peakElement(int arr[], int n)
{
    if (arr[0] >= arr[1]) return 0;
    else if (arr[n - 1] >= arr[n - 2]) return n - 1;
    else {
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) return i;
        }
    }
    return -1; // No peak element found
}

int main() {
    // Test cases
    int arr1[] = {1, 2, 3, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Peak element index in arr1: " << peakElement(arr1, n1) << std::endl;

    int arr2[] = {1, 2, 1, 3, 5, 6, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Peak element index in arr2: " << peakElement(arr2, n2) << std::endl;

    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Peak element index in arr3: " << peakElement(arr3, n3) << std::endl;

    return 0;
}
