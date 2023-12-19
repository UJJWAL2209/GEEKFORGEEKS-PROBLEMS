#include <iostream>
using namespace std;

int isPalindrome(string S) {
    int left = 0;
    int right = S.length() - 1;

    while (left < right) {
        if (S[left] != S[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }

    return 1; // Palindrome
}

int main() {
    // Example usage:
    cout << isPalindrome("abba") << endl;  // Output: 1
    cout << isPalindrome("abc") << endl;   // Output: 0

    return 0;
}
