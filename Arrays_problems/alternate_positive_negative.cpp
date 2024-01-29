#include <iostream>
#include <vector>
using namespace std;

void rearrange(vector<int>& arr, int n) {
    vector<int> pos, neg;

    // Separate positive and negative numbers into separate vectors
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    int i = 0, j = 0, k = 0;
    bool flag = true;

    // Merge positive and negative numbers alternatively
    while (i < pos.size() && j < neg.size()) {
        if (flag)
            arr[k++] = pos[i++];
        else
            arr[k++] = neg[j++];
        flag = !flag;
    }

    // Copy remaining positive numbers, if any
    while (i < pos.size())
        arr[k++] = pos[i++];

    // Copy remaining negative numbers, if any
    while (j < neg.size())
        arr[k++] = neg[j++];
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    rearrange(arr, n);

    cout << "Rearranged array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
