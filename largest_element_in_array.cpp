#include <iostream>
#include <vector>


int largest(std::vector<int> &arr, int n) {
    int largest = arr[0];
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[0]) {
            arr[0] = arr[i];
        }
    }
    
    return arr[0];
}

int main() {
    std::vector<int> numbers = {10, 5, 20, 8, 15};
    int size = numbers.size();

    std::cout << "Original array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int max = largest(numbers, size);
    std::cout << "The largest element in the array is: " << max << std::endl;

    return 0;
}
