#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long maxSum = 0, curSum = 0;
    for(int i = 0; i < n; i++){
        curSum += arr[i];
        if(maxSum < curSum) maxSum = curSum;
        if(curSum < 0) curSum = 0;
    }
    return maxSum;
}
