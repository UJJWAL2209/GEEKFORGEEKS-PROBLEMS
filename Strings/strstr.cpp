#include <iostream>
using namespace std;

int strstr(string s, string x) {
    int n = s.length();
    int m = x.length();

    for (int i = 0; i <= n - m; ++i) {
        int j;

        // Check for a match at the current position
        for (j = 0; j < m; ++j) {
            if (s[i + j] != x[j]) {
                break;
            }
        }

        // If the inner loop reached the end, a match is found
        if (j == m) {
            return i;
        }
    }

    return -1; // Return -1 if no match is found
}

int main() {
    string s1, s2;
    cout << "Enter the main string: ";
    cin >> s1;
    cout << "Enter the substring to find: ";
    cin >> s2;

    int result = strstr(s1, s2);

    if (result != -1) {
        cout << "Substring found at index: " << result << endl;
    } else {
        cout << "Substring not found." << endl;
    }

    return 0;
}
