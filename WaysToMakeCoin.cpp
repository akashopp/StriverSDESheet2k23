#include<bits/stdc++.h>
long f(int i, int val, int denominations[], int n, vector<vector<long>>& dp){
    if(i == n) return (val == 0);
    if(dp[i][val] != -1) return dp[i][val]; 
    long take = 0; 
    long notTake = f(i+1, val, denominations, n, dp);
    if(val - denominations[i] >= 0) take = f(i, val - denominations[i], denominations, n, dp); 
    return dp[i][val] = take + notTake; 
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here 
    int arr[n];
    vector<vector<long>>dp(n, vector<long>(value + 1, -1)); 
    for(int i = 0; i < n; i++) arr[i] = denominations[i];
    return f(0, value, arr, n, dp); 
    return 0; 
}
