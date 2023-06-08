bool isValid(int row, int col, vector<vector<bool>>& vec, int &n){
    int r = row, c = col;
    while(row >= 0 && col >= 0){
        if(vec[row][col] == 1) return 0;
        row--, col--;
    }
    row = r, col = c;
    while(row < n && col >= 0){
        if(vec[row][col] == 1) return 0;
        row++, col--;
    }
    row = r, col = c; 
    while(col >= 0){
        if(vec[row][col] == 1) return 0;
        col--;
    }
    return 1; 
}
void f(int col, vector<vector<bool>>& cur, vector<vector<int>>& ans, int n){
    if(col == n){
        vector<int>temp;
        for(auto it: cur) for(auto itr: it) temp.push_back(itr);
        ans.push_back(temp);
        return;
    }
    for(int row = 0; row < n; row++){
        if(isValid(row, col, cur, n)){
            cur[row][col] = 1;
            f(col+1, cur, ans, n);
            cur[row][col] = 0; 
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>>ans;
    vector<vector<bool>>cur(n, vector<bool>(n, 0)); 
    f(0, cur, ans, n);
    return ans; 
}
