#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1)
    { return false;}
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {return false;}
    }
    return true;
}

int minNumber(vector<int> arr, int N)
 {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += arr[i];
    }
    
    if (isPrime(sum)) {return 0;}

    for (int i = 2; ; ++i) {
        if (isPrime(sum + i))   { return i;}
    }
}

int main() {
    vector<int> arr1 = {2, 4, 6, 8, 12};
    int N1 = 5;
    cout << minNumber(arr1, N1) << endl; // Output: 5

    vector<int> arr2 = {1, 5, 7};
    int N2 = 3;
    cout << minNumber(arr2, N2) << endl; // Output: 0

    return 0;
}
