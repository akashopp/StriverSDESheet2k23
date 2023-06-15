#include <bits/stdc++.h> 
bool isSafe(int node, vector<int>& col, vector<vector<int>>& mat, int n, int color){
    for(int i = 0; i < n; i++){
        if(i != node && mat[node][i] && col[i] == color) return 0;
    }
    return 1;
}
bool f(int node, vector<int>& col, vector<vector<int>>& mat, int m, int n){
    if(node == n) return 1; 
    for(int i = 1; i <= m; i++){
        if(isSafe(node, col, mat, n, i)){
            col[node] = i;
            if(f(node + 1, col, mat, m, n)) return 1; 
            col[node] = 0; 
        }
    }
    return 0; 
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int>col(n, 0);
    return f(0, col, mat, m, n) ? "YES" : "NO";
}
