#include <bits/stdc++.h> 
int f(int i, int j, vector<int>& rack, int &n, vector<vector<int>>& dp){
	if(j == n + 1) return 0;
	if(dp[i][j] != -1) return dp[i][j]; 
	int notTake = f(i, j+1, rack, n, dp); 
	int take = 0; 
	if(i == 0 || rack[i-1] < rack[j-1]) take = rack[j-1] + f(j, j+1, rack, n, dp);
	return dp[i][j] = max(take, notTake);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
	vector<vector<int>>dp(n+1, vector<int>(n+1, -1)); 
	return f(0, 1, rack, n, dp);
}
