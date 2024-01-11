#include <iostream>

using namespace std;

string removeKdigits(string S, int K) {
    int n = S.length();
    
    // Create a string to store the result
    string result = "";
    
    for (char digit : S) {
        // Remove digits from the result string as long as the current digit is smaller and there are still K removals left
        while (!result.empty() && K > 0 && digit < result.back()) {
            result.pop_back();
            K--;
        }
        
        // Push the current digit onto the result string
        result.push_back(digit);
    }
    
    // Remove remaining digits from the end if there are still removals left
    result.resize(result.length() - K);
    
    // Remove leading zeros
    int i = 0;
    while (i < result.length() && result[i] == '0') {
        i++;
    }
    
    result = result.substr(i);
    
    // If the result is empty, return "0"
    return result.empty() ? "0" : result;
}

int main() {
    // Example 1
    string S1 = "149811";
    int K1 = 3;
    cout << removeKdigits(S1, K1) << endl;  // Output: 111
    
    // Example 2
    string S2 = "1002991";
    int K2 = 3;
    cout << removeKdigits(S2, K2) << endl;  // Output: 21
    
    return 0;
}
