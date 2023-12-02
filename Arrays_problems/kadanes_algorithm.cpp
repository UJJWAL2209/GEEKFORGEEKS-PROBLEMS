#include<iostream>
using namespace std;

long long maxSubarraySum(int arr[], int n){
        
        // Your code here
            long long sum = 0;
        long long maxi = LONG_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            
            if(sum>maxi)
            {
                maxi=sum;
            }
            
            if(sum<0){
                sum=0;
            }
        }
    return maxi; 
        
    }

int main(){{
    int arr[] = {4,6,6,3,1,-2,-5,4,-8,-2,-2,1,8,7,9,4,3,2,7,4};
    int n = 20;
    int ans = maxSubarraySum(arr,n);
    cout<<ans<<endl;
    return 0;

}}