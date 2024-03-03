#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string printLargest(vector<string>& arr) {
    // Custom comparison lambda function to sort strings in descending order
    auto compare = [](const string& a, const string& b) {
        string ab = a + b;
        string ba = b + a;
        return ab > ba;
    };

    // Sort the array using custom comparison lambda function
    sort(arr.begin(), arr.end(), compare);

    // Concatenate the sorted strings to get the largest number
    string largestNumber;
    for (const string& s : arr) {
        largestNumber += s;
    }

    return largestNumber;
}

int main() {
    // Example usage
    vector<string> arr1 = {"3", "30", "34", "5", "9"};
    cout << "Largest number: " << printLargest(arr1) << endl; // Output: 9534330

    vector<string> arr2 = {"54", "546", "548", "60"};
    cout << "Largest number: " << printLargest(arr2) << endl; // Output: 6054854654

    return 0;
}
