int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0}; 
void dfs(int row, int col, vector<vector<int>>& image, int color, int newColor, int n, int m, vector<vector<bool>>& vis){
    vis[row][col] = 1; 
    image[row][col] = newColor;
    for(int i = 0; i < 4; i++){
        int nrow = row + dx[i], ncol = col + dy[i]; 
        if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == color && !vis[nrow][ncol]){
            dfs(nrow, ncol, image, color, newColor, n, m, vis); 
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int n = image.size(), m = image[0].size(); 
    vector<vector<bool>>vis(n, vector<bool>(m, 0)); 
    dfs(x, y, image, image[x][y], newColor, n, m, vis); 
    return image;
}
