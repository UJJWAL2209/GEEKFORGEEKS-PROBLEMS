#include<bits/stdc++.h>
using namespace std;

// Function to sort an array of 0s, 1s, and 2s
void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}

int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    int arr[N];
    cout << "Enter the elements of the array (0s, 1s, and 2s): ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort012(arr, N);

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
