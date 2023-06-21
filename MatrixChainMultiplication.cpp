#include <bits/stdc++.h> 
int dp[101][101]; 
int f(int i, int j, vector<int>& arr){
    if(i == j) return 0; 
    if(dp[i][j] != -1) return dp[i][j]; 
    int steps = INT_MAX;
    for(int k = i; k < j; k++){
        steps = min(steps, arr[i-1] * arr[k] * arr[j] + f(i, k, arr) + f(k+1, j, arr)); 
    }
    return dp[i][j] = steps;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    memset(dp, -1, sizeof(dp)); 
    return f(1, N-1, arr); 
}
