#include <iostream>
using namespace std;

int convertFive(int n) {
    int converted = 0;
    int power = 1;

    // Replace all zeros with 5
    while (n > 0) {
        int digit = n % 10;
        if (digit == 0) {
            digit = 5;
        }
        converted += digit * power;
        power *= 10;
        n /= 10;
    }

    return converted;
}

// Example usage
int main() {
    int N1 = 1004;
    cout << "Output for Example 1: " << convertFive(N1) << endl;

    int N2 = 121;
    cout << "Output for Example 2: " << convertFive(N2) << endl;

    return 0;
}
