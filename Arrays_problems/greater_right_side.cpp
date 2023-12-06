#include <iostream>
#include <vector>
using namespace std;

void nextGreatest(vector<int>& arr, int n) {
    int max_from_right = arr[n - 1];
    arr[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--) {
        int temp = arr[i];
        arr[i] = max_from_right;
        if (temp > max_from_right)
            max_from_right = temp;
    }
}

int main() {
    // Example usage:
    vector<int> arr1 = {16, 17, 4, 3, 5, 2};
    int n1 = arr1.size();

    nextGreatest(arr1, n1);

    cout << "Output for arr1: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    vector<int> arr2 = {2, 3, 1, 9};
    int n2 = arr2.size();

    nextGreatest(arr2, n2);

    cout << "Output for arr2: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
