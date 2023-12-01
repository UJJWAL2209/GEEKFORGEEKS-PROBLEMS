#include <iostream>
using namespace std;

pair<long long, int> maxNtype(long long A[], int N) {
    int asc = 0, desc = 0;
    long long max_element = A[0];

    for (int i = 1; i < N; ++i) {
        if (A[i] > max_element)
            max_element = A[i];

        if (A[i] > A[i - 1])
            asc++;
        else if (A[i] < A[i - 1])
            desc++;
    }

    if (asc == N - 1) {
        return make_pair(max_element, 1); // Ascending
    } else if (desc == N - 1) {
        return make_pair(max_element, 2); // Descending
    } else if (A[N - 1] > A[0]) {
        return make_pair(max_element, 3); // Ascending Rotated
    } else {
        return make_pair(max_element, 4); // Descending Rotated
    }
}

int main() {
    int N = 5;
    long long A1[] = {2, 1, 5, 4, 3};
    long long A2[] = {3, 4, 5, 1, 2};

    pair<long long, int> result1 = maxNtype(A1, N);
    pair<long long, int> result2 = maxNtype(A2, N);

    cout << "Output 1: " << result1.first << " " << result1.second << endl;
    cout << "Output 2: " << result2.first << " " << result2.second << endl;

    return 0;
}
