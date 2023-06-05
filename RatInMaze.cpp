#include <bits/stdc++.h> 
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1}; 
void f(int row, int col, vector<vector<int>>& maze, vector<vector<bool>>& vis, int &n, vector<pair<int, int>>& cur, 
                          vector<vector<int>>& ans){
  if(row == n-1 && col == n-1){
    vector<int>temp(n*n, 0);
    for(auto it: cur){
      temp[it.first*n + it.second] = 1; 
    }
    ans.push_back(temp);
    return;
  }
  vis[row][col] = 1; 
  for(int i = 0; i < 4; i++){
    int nrow = row + dx[i], ncol = col + dy[i];
    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && !vis[nrow][ncol] && maze[nrow][ncol]){
      cur.push_back({nrow, ncol}); 
      f(nrow, ncol, maze, vis, n, cur, ans); 
      cur.pop_back();
    }
  }
  vis[row][col] = 0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<bool>>vis(n, vector<bool>(n, 0)); 
  vector<pair<int, int>>cur;
  cur.push_back({0, 0}); 
  vector<vector<int>>ans;
  f(0, 0, maze, vis, n, cur, ans); 
  return ans;
}
