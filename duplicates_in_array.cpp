#include <iostream>
#include <vector>
#include <map>
#include<algorithm>

using namespace std;

std::vector<int> duplicates(int a[], int n) {
    std::map<int, int> freq;

    for (int i = 0; i < n; ++i) {
        freq[a[i]]++; // Count the frequency of each element
    }

    std::vector<int> result;
    for (const auto &pair : freq) {
        if (pair.second > 1) { // If frequency is more than 1, add to result
            result.push_back(pair.first);
        }
    }

    if (result.empty()) {
        result.push_back(-1);
    } else {
        std::sort(result.begin(), result.end());
    }

    return result;
}

int main() {
    int N1 = 4;
    int arr1[] = {0, 3, 1, 2};
    std::vector<int> res1 = duplicates(arr1, N1);

    std::cout << "Output for N=4: ";
    for (int num : res1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int N2 = 5;
    int arr2[] = {2, 3, 1, 2, 3};
    std::vector<int> res2 = duplicates(arr2, N2);

    std::cout << "Output for N=5: ";
    for (int num : res2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
