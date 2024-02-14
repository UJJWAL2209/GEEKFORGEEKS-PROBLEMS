#include <iostream>

// Function declaration
int minJumps(int arr[], int n);

int main() {
    // Example usage
    int arr[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int minJumpsResult = minJumps(arr, n);

    if (minJumpsResult == -1) {
        std::cout << "It is not possible to reach the end of the array." << std::endl;
    } else {
        std::cout << "Minimum number of jumps to reach the end of the array: " << minJumpsResult << std::endl;
    }

    return 0;
}
    int minJumps(int arr[], int n){
        // Your code here
          int jumps =0;
        int currmax =0;
        int maxpos =0;
        for(int i=0;i<n;i++){
            if(i > maxpos){
                return -1;
                
            }
            if(maxpos >= n-1){
                return jumps;
            }
            if(currmax < i+arr[i]){
                currmax  = i+arr[i];
            }
            if(i == maxpos){
                maxpos = currmax;
                jumps++;
            }
        }
    }