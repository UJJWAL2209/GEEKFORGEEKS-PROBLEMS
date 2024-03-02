#include <iostream>
#include <unordered_map>

using namespace std;

int firstElementKTime(int n, int k, int a[]) {
    unordered_map<int, int> freqMap;

    for (int i = 0; i < n; i++) {
        freqMap[a[i]]++;
        if (freqMap[a[i]] == k) {
            return a[i];
        }
    }

    return -1;
}

int main() {
    // Example usage
    int a[] = {1, 2, 3, 4, 2, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;

    int result = firstElementKTime(n, k, a);

    if (result != -1) {
        cout << "First element occurring " << k << " times: " << result << endl;
    } else {
        cout << "No element occurs " << k << " times." << endl;
    }

    return 0;
}
