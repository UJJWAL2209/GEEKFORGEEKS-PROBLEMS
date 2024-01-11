#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int N) {
    vector<long long> result(N, -1);  // Initialize result array with -1
    stack<int> st;  // Stack to store indices of elements
    
    for (int i = 0; i < N; ++i) {
        // Check if the stack is not empty and the current element is greater than the element at the top of the stack
        while (!st.empty() && arr[i] > arr[st.top()]) {
            result[st.top()] = arr[i];  // Update the result for the element at the top of the stack
            st.pop();  // Pop the index from the stack
        }
        
        // Push the current index onto the stack
        st.push(i);
    }
    
    return result;
}

int main() {
    // Example 1
    int N1 = 4;
    vector<long long> arr1 = {1, 3, 2, 4};
    vector<long long> result1 = nextLargerElement(arr1, N1);
    
    cout << "Output 1: ";
    for (long long num : result1) {
        cout << num << " ";
    }
    cout << endl;  // Output: 3 4 4 -1
    
    // Example 2
    int N2 = 5;
    vector<long long> arr2 = {6, 8, 0, 1, 3};
    vector<long long> result2 = nextLargerElement(arr2, N2);
    
    cout << "Output 2: ";
    for (long long num : result2) {
        cout << num << " ";
    }
    cout << endl;  // Output: 8 -1 1 3 -1
    
    return 0;
}
