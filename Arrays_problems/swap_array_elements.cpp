#include <iostream>

// Function to swap elements in an array
void swapElements(int arr[], int n) {
    for(int i = 0; i < n - 2; i++) {
        int j = i + 2;
        // Swapping elements
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    // Example array
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Displaying original array
    std::cout << "Original Array: ";
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Calling swapElements function
    swapElements(arr, n);

    // Displaying array after swapping
    std::cout << "Array after swapping: ";
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
