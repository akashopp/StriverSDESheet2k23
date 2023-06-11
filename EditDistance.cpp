#include<bits/stdc++.h>
int dp[1001][1001]; 
int f(int i, int j, string &s, string &t, int &n, int &m){
    if(i == n) return m - j; 
    if(j == m) return n - i; 
    if(dp[i][j] != -1) return dp[i][j]; 
    if(s[i] == t[j]) return f(i+1, j+1, s, t, n, m);
    return dp[i][j] = 1 + min(f(i+1, j+1, s, t, n, m), min(f(i, j+1, s, t, n, m), f(i+1, j, s, t, n, m))); 
}
int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.size(), m = str2.size(); 
    memset(dp, -1, sizeof(dp)); 
    return f(0, 0, str1, str2, n, m); 
}
