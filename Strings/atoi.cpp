#include <iostream>

using namespace std;

int atoi(string str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Handling the sign if present
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }

    // Processing the digits
    while (i < str.length()) {
        // Check if the character is a digit
        if (isdigit(str[i])) {
            // Convert character to integer and update the result
            result = result * 10 + (str[i] - '0');
            i++;
        } else {
            // If a non-digit character is encountered, return -1
            return -1;
        }
    }

    // Applying the sign to the result
    return sign * result;
}

int main() {
    // Example usage
    string str1 = "123";
    cout << atoi(str1) << endl; // Output: 123

    string str2 = "21a";
    cout << atoi(str2) << endl; // Output: -1

    return 0;
}
