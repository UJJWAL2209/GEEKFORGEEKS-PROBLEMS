#include <iostream>
#include <vector>

using namespace std;

string multiplyStrings(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();

    if (n1 == 0 || n2 == 0) {
        return "0";
    }

    // Handle the sign
    int sign = 1;
    if (s1[0] == '-') {
        sign *= -1;
        s1.erase(s1.begin());
        n1--;
    }
    if (s2[0] == '-') {
        sign *= -1;
        s2.erase(s2.begin());
        n2--;
    }

    // Initialize result array with zeros
    vector<int> result(n1 + n2, 0);

    // Traverse both strings from right to left
    for (int i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        int num1 = s1[i] - '0';

        // Traverse s2 from right to left for each digit of s1
        for (int j = n2 - 1; j >= 0; j--) {
            int num2 = s2[j] - '0';

            // Multiply current digits and add to the result
            int sum = num1 * num2 + result[i + j + 1] + carry;
            result[i + j + 1] = sum % 10;
            carry = sum / 10;
        }

        // Add carry to the next higher position in result
        result[i] += carry;
    }

    // Remove leading zeros in the result
    int i = 0;
    while (i < n1 + n2 && result[i] == 0) {
        i++;
    }

    // If the result is zero, return "0"
    if (i == n1 + n2) {
        return "0";
    }

    // Convert result vector to a string
    string res = "";
    for (; i < n1 + n2; i++) {
        res += to_string(result[i]);
    }

    // Include the sign in the result
    return (sign == -1) ? "-" + res : res;
}

int main() {
    string s1 = "986";
    string s2 = "-24";

    cout << multiplyStrings(s1, s2) << endl;  // Output: -23664

    return 0;
}
