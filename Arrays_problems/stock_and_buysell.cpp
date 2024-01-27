#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> stockBuySell(int A[], int N) {
    vector<vector<int>> result;
    
    int buy = -1, sell = -1;
    for (int i = 1; i < N; i++) {
        if (A[i] > A[i - 1]) {
            if (buy == -1)
                buy = i - 1;
            sell = i;
        } else {
            if (buy != -1) {
                result.push_back({buy, sell});
                buy = sell = -1;
            }
        }
    }
    
    if (buy != -1 && sell != -1)
        result.push_back({buy, sell});
    
    return result;
}

int main() {
    int N1 = 7;
    int A1[] = {100, 180, 260, 310, 40, 535, 695};
    vector<vector<int>> result1 = stockBuySell(A1, N1);
    for (auto& pair : result1) {
        cout << "(" << pair[0] << " " << pair[1] << ") ";
    }
    cout << endl;
    
    int N2 = 5;
    int A2[] = {4, 2, 2, 2, 4};
    vector<vector<int>> result2 = stockBuySell(A2, N2);
    for (auto& pair : result2) {
        cout << "(" << pair[0] << " " << pair[1] << ") ";
    }
    cout << endl;
    
    return 0;
}
