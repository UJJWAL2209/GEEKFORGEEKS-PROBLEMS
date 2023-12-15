#include <stdio.h>

int findFirstOne(int arr[], int n) {
    int i = 0;
    int j = n - 1;

    while (i <= j) {
        int mid = (i + j) / 2;
        
        if (arr[mid] == 1 && (mid == 0 || arr[mid - 1] == 0)) {
            return mid;
        } else if (arr[mid - 1] == 1) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {0, 0, 0, 1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = findFirstOne(arr, n);

    if (result != -1) {
        printf("The index of the first occurrence of 1 is: %d\n", result);
    } else {
        printf("No occurrence of 1 in the array\n");
    }

    return 0;
}
