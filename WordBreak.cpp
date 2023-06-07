#include <bits/stdc++.h> 
bool f(int i, vector<string>& arr, string &target, int n, vector<int>& dp){
    if(i == n) return 1;
    if(dp[i] != -1) return dp[i];
    bool flag = 0; 
    for(auto it: arr){
        int len = it.size(); 
        if(it == target.substr(i, len)) flag = f(i+len, arr, target, n, dp);
        if(flag) break;  
    }
    return dp[i] = flag;
}
bool wordBreak(vector < string > & arr, int m, string & target) {
    // Write your code here.
    int n = target.size(); 
    vector<int>dp(n, -1); 
    return f(0, arr, target, n, dp); 
}
