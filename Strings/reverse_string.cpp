#include <iostream>
using namespace std;

string reverseWord(string str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        // Swap characters at start and end indices
        swap(str[start], str[end]);

        // Move indices towards each other
        start++;
        end--;
    }

    return str;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string result = reverseWord(s);

    cout << "Reversed string: " << result << endl;

    return 0;
}
