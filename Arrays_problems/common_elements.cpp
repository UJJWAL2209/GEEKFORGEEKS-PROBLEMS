#include <iostream>
#include <vector>
using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
    vector<int> result;

    // Initialize indices for A, B, and C
    int i = 0, j = 0, k = 0;

    // Traverse through all three arrays
    while (i < n1 && j < n2 && k < n3) {
        // If the current elements in all three arrays are equal
        if (A[i] == B[j] && B[j] == C[k]) {
            // Add the common element to the result vector
            result.push_back(A[i]);

            // Move to the next elements in all three arrays
            i++;
            j++;
            k++;

            // Skip duplicate elements in A
            while (i < n1 && A[i] == A[i - 1]) {
                i++;
            }

            // Skip duplicate elements in B
            while (j < n2 && B[j] == B[j - 1]) {
                j++;
            }

            // Skip duplicate elements in C
            while (k < n3 && C[k] == C[k - 1]) {
                k++;
            }
        }
        // If the current element in A is smaller than the current element in B
        else if (A[i] < B[j]) {
            // Move to the next element in A
            i++;
        }
        // If the current element in B is smaller than the current element in C
        else if (B[j] < C[k]) {
            // Move to the next element in B
            j++;
        }
        // If the current element in C is smaller than the current elements in A and B
        else {
            // Move to the next element in C
            k++;
        }
    }

    // Return the result vector
    return result;
}

int main() {
    int n1 = 3;
    int A[] = {3, 3, 3};

    int n2 = 3;
    int B[] = {3, 3, 3};

    int n3 = 3;
    int C[] = {3, 3, 3};

    // Call the function to find common elements
    vector<int> result = commonElements(A, B, C, n1, n2, n3);

    // Print the result
    if (result.empty()) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
