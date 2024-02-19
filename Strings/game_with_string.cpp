#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int minValue(string s, int k) {
    // Count the frequency of each character
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // Store the frequencies in a vector
    vector<int> counts;
    for (auto& p : freq) {
        counts.push_back(p.second);
    }

    // Sort the frequencies in non-increasing order
    sort(counts.begin(), counts.end(), greater<int>());

    // Remove characters greedily
    for (int i = 0; i < k; i++) {
        if (counts.empty()) break; // No more characters to remove
        counts[0]--; // Decrement the count of the character with highest frequency
        if (counts[0] == 0) counts.erase(counts.begin()); // Remove if count becomes zero
        // Reorder the vector to maintain non-increasing order
        sort(counts.begin(), counts.end(), greater<int>());
    }

    // Calculate the value of the modified string
    int value = 0;
    for (int count : counts) {
        value += count * count;
    }

    return value;
}

int main() {
    // Test cases
    cout << minValue("abccc", 1) << endl; // Output: 6
    cout << minValue("aabcbcbcabcc", 3) << endl; // Output: 27
    return 0;
}
