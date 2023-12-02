#include <iostream>
#include <vector>

using namespace std;

int search(int arr[], int n, int k) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            return i + 1; // Position of first element is considered as 1
        }
    }
    return -1; // Return -1 if the number is not found in array
}

// Example usage
int main() {
    int Arr1[] = {9, 7, 2, 16, 4};
    int N1 = 5, K1 = 16;
    cout << "Output for Example 1: " << search(Arr1, N1, K1) << endl;

    int Arr2[] = {1, 22, 57, 47, 34, 18, 66};
    int N2 = 7, K2 = 98;
    cout << "Output for Example 2: " << search(Arr2, N2, K2) << endl;

    return 0;
}
