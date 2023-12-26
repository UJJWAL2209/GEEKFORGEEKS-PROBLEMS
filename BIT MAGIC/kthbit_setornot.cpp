#include <iostream>
using namespace std;

bool checkKthbit(int N, int K) {
    // Shifting the 1 to the Kth position and using bitwise AND with N
    // If the result is non-zero, then the Kth bit is set (1), otherwise not set (0)
    return (N & (1 << K)) != 0;
}

int main() {
    // Example usage
    int N1 = 4, K1 = 0;
    cout << (checkKthbit(N1, K1) ? "Yes" : "No") << endl;

    int N2 = 4, K2 = 2;
    cout << (checkKthbit(N2, K2) ? "Yes" : "No") << endl;

    int N3 = 500, K3 = 3;
    cout << (checkKthbit(N3, K3) ? "Yes" : "No") << endl;

    return 0;
}
