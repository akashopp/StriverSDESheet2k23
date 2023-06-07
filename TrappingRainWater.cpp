#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    int low = 0, high = n-1;
    long leftMax = 0, rightMax = 0, ans = 0;
    while(low <= high){
        if(arr[low] <= arr[high]){
            if(arr[low] >= leftMax) leftMax = arr[low];
            else ans += leftMax - arr[low];
            low++;
        }else{
            if(arr[high] >= rightMax) rightMax = arr[high];
            else ans += rightMax - arr[high];
            high--; 
        }
    }
    return ans;
}
