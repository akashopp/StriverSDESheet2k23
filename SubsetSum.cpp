#include <bits/stdc++.h> 
bool f(int i, int k, vector<int>& arr, int &n, vector<vector<int>>& dp){
    if(i == n) return (k == 0);
    if(dp[i][k] != -1) return dp[i][k]; 
    bool notTake = f(i+1, k, arr, n, dp), take = 0; 
    if(k - arr[i] >= 0) take = f(i+1, k - arr[i], arr, n, dp); 
    return dp[i][k] = notTake | take; 
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n+1, vector<int>(k+1, -1)); 
    return f(0, k, arr, n, dp); 
}
