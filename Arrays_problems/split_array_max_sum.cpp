#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to check if it is possible to split the array with a given maximum sum
bool isPossible(int arr[], int n, int k, int mid) {
    int count = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum > mid) {
            count++;
            sum = arr[i];
        }
    }
    count++;  // The last subarray
    return count <= k;
}

// Function to find the maximum sum subarray after splitting the array into K subarrays
int splitArray(int arr[], int n, int k) {
    int left = *max_element(arr, arr + n);
    int right = accumulate(arr, arr + n, 0);

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isPossible(arr, n, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int N, K;
    cin >> N >> K;

    int arr[N];
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int result = splitArray(arr, N, K);
    cout << result << endl;

    return 0;
}
