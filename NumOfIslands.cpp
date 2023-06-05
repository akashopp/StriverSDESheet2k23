#include<bits/stdc++.h>
int dx[8] = {0, 0, -1, 1, 1, -1, -1, 1}, dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
void dfs(int row, int col, vector<vector<bool>>& vis, vector<vector<int>>& grid, int &n, int &m){
   vis[row][col] = 1; 
   for(int i = 0; i < 8; i++){
      int nrow = row + dx[i], ncol = col + dy[i];
      if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] && !vis[nrow][ncol]) dfs(nrow, ncol, vis, grid, n, m);
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   int ans = 0; 
   vector<vector<int>>grid(n, vector<int>(m));
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++) grid[i][j] = arr[i][j];
   }
   vector<vector<bool>>vis(n, vector<bool>(m, 0));
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(!vis[i][j] && grid[i][j]) dfs(i, j, vis, grid, n, m), ans++;
      }
   }
   return ans;
}
