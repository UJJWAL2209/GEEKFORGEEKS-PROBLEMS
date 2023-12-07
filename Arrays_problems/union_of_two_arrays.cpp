#include <iostream>
#include <unordered_set>

using namespace std;

int doUnion(int a[], int n, int b[], int m) {
    unordered_set<int> unionSet;

    // Insert elements from array 'a' into the set
    for (int i = 0; i < n; ++i) {
        unionSet.insert(a[i]);
    }

    // Insert elements from array 'b' into the set
    for (int i = 0; i < m; ++i) {
        unionSet.insert(b[i]);
    }

    return unionSet.size(); // Return the size of the union set
}

int main() {
    // Example usage
    int a1[] = {1, 2, 3, 4, 5};
    int n = 5;
    int b1[] = {1, 2, 3};
    int m = 3;
    cout << "Count of elements in union: " << doUnion(a1, n, b1, m) << endl;

    int a2[] = {85, 25, 1, 32, 54, 6};
    n = 6;
    int b2[] = {85, 2};
    m = 2;
    cout << "Count of elements in union: " << doUnion(a2, n, b2, m) << endl;

    return 0;
}
