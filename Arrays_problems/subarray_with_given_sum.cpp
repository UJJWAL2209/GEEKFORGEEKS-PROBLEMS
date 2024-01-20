#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, int sum){
    int curr_sum = arr[0], start = 0;
    vector<int> result;

    for (int end = 1; end <= n; ++end) {
        while (curr_sum > sum && start < end - 1) {
            curr_sum -= arr[start];
            ++start;
        }

        if (curr_sum == sum) {
            result.push_back(start + 1); // 1-based indexing
            result.push_back(end);
            return result;
        }

        if (end < n) {
            curr_sum += arr[end];
        }
    }

    result.push_back(-1); // If no subarray is found
    return result;
}

int main() {
    int N1 = 5, S1 = 12;
    int A1[] = {1, 2, 3, 7, 5};
    vector<int> result1 = subarraySum(A1, N1, S1);

    cout << "Example 1: ";
    for (int i : result1) {
        cout << i << " ";
    }
    cout << endl;

    int N2 = 10, S2 = 15;
    int A2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> result2 = subarraySum(A2, N2, S2);

    cout << "Example 2: ";
    for (int i : result2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
