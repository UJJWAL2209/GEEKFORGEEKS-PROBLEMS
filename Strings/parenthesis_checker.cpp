#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool ispar(string expression) {
        stack<char> s;
        for (char c : expression) {
            if (c == '(' || c == '[' || c == '{') {
                s.push(c);
            } else {
                if (s.empty()) {
                    return false;
                } else if ((c == ')' && s.top() == '(') ||
                           (c == ']' && s.top() == '[') ||
                           (c == '}' && s.top() == '{')) {
                    s.pop();
                } else {
                    return false;
                }
            }
        }
        return s.empty();
    }
};

int main() {
    Solution solution;

    // Example usage
    string exp1 = "{([])}";
    string exp2 = "()";
    string exp3 = "([)]";

    cout << (solution.ispar(exp1) ? "balanced" : "not balanced") << endl;
    cout << (solution.ispar(exp2) ? "balanced" : "not balanced") << endl;
    cout << (solution.ispar(exp3) ? "balanced" : "not balanced") << endl;

    return 0;
}
