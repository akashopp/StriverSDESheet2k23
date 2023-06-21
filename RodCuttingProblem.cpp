#include<bits/stdc++.h>
int dp[101];
int f(int i, int n, vector<int>& price){
	if(i == n) return 0;
	if(dp[i] != -1) return dp[i];
	int cost = INT_MIN;
	for(int k = i; k < n; k++){
		cost = max(cost, price[k-i] + f(k+1, n, price));
	}
	return dp[i] = cost; 
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	memset(dp, -1, sizeof(dp));
	return f(0, n, price); 
}
