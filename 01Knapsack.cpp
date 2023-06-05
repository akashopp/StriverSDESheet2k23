int f(int i, int w, vector<int>& values, vector<int>& weights, int n, 
							vector<vector<int>>& dp){
	if(i == n) return 0; 
	if(dp[i][w] != -1) return dp[i][w]; 
	int take = 0; 
	if(w - weights[i] >= 0) take = values[i] + f(i+1, w - weights[i], values, weights, n, dp); 
	int notTake = f(i+1, w, values, weights, n, dp);
	return dp[i][w] = max(notTake, take); 
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<vector<int>>dp(n, vector<int>(w+1, -1)); 
	return f(0, w, values, weights, n, dp); 
}
