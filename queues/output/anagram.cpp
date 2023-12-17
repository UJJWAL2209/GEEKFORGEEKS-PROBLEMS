#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string a, string b) {
    // If the lengths of the strings are different, they can't be anagrams
    if (a.length() != b.length()) {
        return false;
    }

    // Create a map to store the frequency of characters in both strings
    unordered_map<char, int> freqMap;

    // Update frequency map for string A
    for (char c : a) {
        freqMap[c]++;
    }

    // Update frequency map for string B
    for (char c : b) {
        freqMap[c]--;
    }

    // Check if all frequencies in the map are zero
    for (auto it : freqMap) {
        if (it.second != 0) {
            return false;
        }
    }

    // If all frequencies are zero, the strings are anagrams
    return true;
}

int main() {
    // Test cases
    cout << (isAnagram("geeksforgeeks", "forgeeksgeeks") ? "YES" : "NO") << endl;
    cout << (isAnagram("allergy", "allergic") ? "YES" : "NO") << endl;

    return 0;
}
