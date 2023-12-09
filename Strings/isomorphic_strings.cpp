#include <iostream>
#include <unordered_map>

using namespace std;

bool areIsomorphic(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;

    unordered_map<char, char> mapping;
    unordered_map<char, bool> used;

    for (int i = 0; i < str1.length(); ++i) {
        char c1 = str1[i];
        char c2 = str2[i];

        if (mapping.find(c1) != mapping.end()) {
            if (mapping[c1] != c2)
                return false;
        } else {
            if (used[c2])
                return false;

            mapping[c1] = c2;
            used[c2] = true;
        }
    }

    return true;
}

int main() {
    string str1 = "aab";
    string str2 = "xxy";

    if (areIsomorphic(str1, str2))
        cout << "Isomorphic" << endl;
    else
        cout << "Not Isomorphic" << endl;

    return 0;
}
