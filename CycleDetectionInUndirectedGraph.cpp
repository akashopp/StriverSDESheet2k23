bool dfs(int node, int par, vector<int>adj[], vector<bool>& vis){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(it, node, adj, vis)) return 1; 
        }else if(it != par) return 1; 
    }
    return 0; 
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>adj[n+1];
    for(auto &it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]); 
    }
    vector<bool>vis(n+1, 0); 
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(dfs(i, -1, adj, vis)) return "Yes";
        }
    }
    return "No"; 
}
