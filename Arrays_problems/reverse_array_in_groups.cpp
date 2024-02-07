#include<bits/stdc++.h>

using namespace std;

void reverseArray(vector<long long int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void reverseInGroups(vector<long long int>& arr, int N, int K) {
    for (int i = 0; i < N; i += K) {
        int start = i;
        int end = min(i + K - 1, N - 1); // Ensure not to go beyond array bounds
        reverseArray(arr, start, end);
    }
}

int main() {
    vector<long long int> arr1 = {1, 2, 3, 4, 5};
    int N1 = arr1.size();
    int K1 = 3;
    reverseInGroups(arr1, N1, K1);
    for (int i = 0; i < N1; i++)
        cout << arr1[i] << " ";
    cout << endl;

    vector<long long int> arr2 = {5, 6, 8, 9};
    int N2 = arr2.size();
    int K2 = 3;
    reverseInGroups(arr2, N2, K2);
    for (int i = 0; i < N2; i++)
        cout << arr2[i] << " ";
    cout << endl;

    return 0;
}

