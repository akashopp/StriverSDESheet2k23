#include <bits/stdc++.h> 
bool isPali(int i, int j, string &s){
    while(i < j){
        if(s[i] != s[j]) return 0;
        i++, j--;
    }
    return 1; 
}
int dp[101];
int f(int ind, string &s, int &n){
    if(ind == n) return 0; 
    if(dp[ind] != -1) return dp[ind]; 
    int cost = INT_MAX;
    for(int i = ind; i < n; i++){
        if(isPali(ind, i, s)) cost = min(cost, 1 + f(i+1, s, n)); 
    }
    return dp[ind] = cost;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();
    memset(dp, -1, sizeof(dp));
    return f(0, str, n) - 1; 
}
