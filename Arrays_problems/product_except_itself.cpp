#include <iostream>
#include <vector>

using namespace std;

vector<long long> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    // Initialize left and right product arrays
    vector<long long> leftProduct(n, 1);
    vector<long long> rightProduct(n, 1);

    // Calculate left product for each element
    long long left = 1;
    for (int i = 1; i < n; i++) {
        left *= nums[i - 1];
        leftProduct[i] = left;
    }

    // Calculate right product for each element
    long long right = 1;
    for (int i = n - 2; i >= 0; i--) {
        right *= nums[i + 1];
        rightProduct[i] = right;
    }

    // Calculate the final product array
    vector<long long> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = leftProduct[i] * rightProduct[i];
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<long long> result = productExceptSelf(nums);

    cout << "Product array: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
   