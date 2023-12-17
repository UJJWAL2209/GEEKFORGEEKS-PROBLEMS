#include <iostream>

using namespace std;

	int findMaxSum(int *arr, int n) {
	    // code here
	if(n==1){
	    return arr[0];
	}
    
    int a,b,c;
    a=arr[0];
    b=max(a,arr[1]);
    for(int i=2;i<n;i++)
    {
        c=max(b,a+arr[i]);
        a=b;
        b=c;
    }
    return c;
	};

int main() {
    // Test case
    int arr1[] = {1, -2, 3, -1, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Max Sum: " << findMaxSum(arr1, n1) << endl;

    // Additional test case
    int arr2[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Max Sum: " << findMaxSum(arr2, n2) << endl;

    return 0;
}
