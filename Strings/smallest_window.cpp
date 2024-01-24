#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string S, string P) {
    int n = S.length();
    int m = P.length();

    if (n < m)
        return "-1";

    vector<int> countP(26, 0);
    vector<int> countS(26, 0);

    // Count the frequency of characters in P
    for (char ch : P)
        countP[ch - 'a']++;

    int start = 0, startIndex = -1;
    int minLength = INT_MAX;
    int count = 0;

    // Traverse the string S
    for (int i = 0; i < n; i++) {
        countS[S[i] - 'a']++;

        // Check if a character in P is found in S
        if (countP[S[i] - 'a'] > 0 && countS[S[i] - 'a'] <= countP[S[i] - 'a'])
            count++;

        // If all characters in P are found in the current window
        if (count == m) {
            // Try to minimize the window by removing extra characters from the beginning
            while (countS[S[start] - 'a'] > countP[S[start] - 'a'] || countP[S[start] - 'a'] == 0) {
                if (countS[S[start] - 'a'] > countP[S[start] - 'a'])
                    countS[S[start] - 'a']--;
                start++;
            }

            // Update the minimum window size and starting index
            int windowSize = i - start + 1;
            if (windowSize < minLength) {
                minLength = windowSize;
                startIndex = start;
            }
        }
    }

    // If no window found
    if (startIndex == -1)
        return "-1";

    // Return the smallest window substring
    return S.substr(startIndex, minLength);
}

int main() {
    string S1 = "timetopractice";
    string P1 = "toc";
    cout << smallestWindow(S1, P1) << endl;  // Output: toprac

    string S2 = "zoomlazapzo";
    string P2 = "oza";
    cout << smallestWindow(S2, P2) << endl;  // Output: apzo

    return 0;
}
