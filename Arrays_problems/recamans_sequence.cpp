#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> recamanSequence(int n) {
    vector<int> result;
    unordered_set<int> seen;
    result.push_back(0);
    seen.insert(0);

    for (int i = 1; i < n; ++i) {
        int next = result[i - 1] - i;
        if (next < 0 || seen.find(next) != seen.end()) {
            next = result[i - 1] + i;
        }
        result.push_back(next);
        seen.insert(next);
    }

    return result;
}

int main() {
    int n = 5;
    vector<int> sequence = recamanSequence(n);
    cout << "Recaman's sequence for n = " << n << ": ";
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
