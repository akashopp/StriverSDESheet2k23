#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int>lis; 
    int maxi = 1;
    lis.push_back(arr[0]); 
    for(int i = 1; i < n; i++){
        if(lis.back() < arr[i]) lis.push_back(arr[i]), maxi++; 
        else{
            int ind = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[ind] = arr[i];
        }
    }
    return maxi; 
}
