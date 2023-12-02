#include <iostream>
#include <string>

using namespace std;

int findSum(string str) {
    int sum = 0;
    int currentNum = 0;

    for (char ch : str) {
        if (isdigit(ch)) {
            currentNum = currentNum * 10 + (ch - '0'); // Forming the number
        } else {
            sum += currentNum; // Adding the formed number to the sum
            currentNum = 0; // Resetting currentNum for the next number
        }
    }

    // Adding the last formed number (if any) to the sum
    sum += currentNum;

    return sum;
}

int main() {
    string input1 = "1abc23";
    cout << "Sum for '1abc23': " << findSum(input1) << endl;

    string input2 = "geeks4geeks";
    cout << "Sum for 'geeks4geeks': " << findSum(input2) << endl;

    return 0;
}
