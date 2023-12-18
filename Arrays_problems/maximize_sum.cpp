#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long Maximize(int arr[], int n) {
    // Sort the array
    sort(arr, arr + n);

    // Calculate the result using the formula
    long long result = 0;
    for (int i = 0; i < n; i++) {
        result = (result + (long long)arr[i] * i) % MOD;
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << Maximize(arr, n) << endl;
    }
    return 0;
}
