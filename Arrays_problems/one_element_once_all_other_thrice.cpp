#include <iostream>
#include <vector>

using namespace std;

int singleElement(vector<int>& arr) {
    int ones = 0, twos = 0, commonBits;

    for (int i = 0; i < arr.size(); i++) {
        // Update twos if the corresponding bit in ones is set
        twos |= (ones & arr[i]);

        // XOR the element with ones to set the bit if it appears the first time
        ones ^= arr[i];

        // The commonBits represents the bits that are set in both ones and twos
        commonBits = ~(ones & twos);

        // Remove the commonBits from both ones and twos
        ones &= commonBits;
        twos &= commonBits;
    }

    return ones;
}

int main() {
    // Example usage
    vector<int> arr1 = {1, 10, 1, 1};
    cout << "Output for Example 1: " << singleElement(arr1) << endl; // Output: 10

    vector<int> arr2 = {3, 2, 1, 34, 34, 1, 2, 34, 2, 1};
    cout << "Output for Example 2: " << singleElement(arr2) << endl; // Output: 3

    return 0;
}
