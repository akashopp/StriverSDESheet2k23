#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    int fresh = 0, ans = 0, dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0}; 
    queue<pair<pair<int, int>, int>>q; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2) q.push({{i, j}, 0}); 
            fresh += (grid[i][j] == 1);
        }
    }
    while(!q.empty()){
        int row = q.front().first.first, col = q.front().first.second, time = q.front().second; 
        q.pop(); 
        ans = max(ans, time); 
        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i], ncol = col + dy[i]; 
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && (grid[nrow][ncol]&1)){
                grid[nrow][ncol] = 2; 
                q.push({{nrow, ncol}, time + 1}); 
                fresh--; 
            }
        }
    }
    return (!fresh ? ans : -1); 
}
