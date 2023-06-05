#include <bits/stdc++.h> 
int f(int row, int col, int &n, int &m, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if(row == n-1 && col == m-1) return grid[n-1][m-1];
    if(dp[row][col] != -1) return dp[row][col]; 
    int right = 1e9, down = 1e9;
    if(row + 1 < n) down = grid[row][col] + f(row + 1, col, n, m, grid, dp);
    if(col + 1 < m) right = grid[row][col] + f(row, col + 1, n, m, grid, dp); 
    return dp[row][col] = min(down, right); 
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size(), m = grid[0].size(); 
    vector<vector<int>>dp(n, vector<int>(m, -1));
    return f(0, 0, n, m, grid, dp); 
}
