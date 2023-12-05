#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> leader(int arr[], int n) {
    vector<int> leaders;
    int maxRight = arr[n - 1];
    leaders.push_back(maxRight);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxRight) {
            maxRight = arr[i];
            leaders.push_back(maxRight);
        }
    }

    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    int n1 = 6;
    int arr1[] = {16, 17, 4, 3, 5, 2};
    vector<int> result1 = leader(arr1, n1);

    cout << "Leaders in array 1: ";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << " ";
    }
    cout << endl;

    int n2 = 5;
    int arr2[] = {1, 2, 3, 4, 0};
    vector<int> result2 = leader(arr2, n2);

    cout << "Leaders in array 2: ";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << " ";
    }
    cout << endl;

    return 0;
}
