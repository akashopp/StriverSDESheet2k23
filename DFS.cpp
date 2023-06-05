void dfs(int node, vector<int>adj[], vector<bool>& vis, vector<pair<int, int>>& vec, int cnt){
    vec.push_back({node, cnt});
    vis[node] = 1; 
    for(auto it: adj[node]){
        if(!vis[it]) dfs(it, adj, vis, vec, cnt); 
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<bool>vis(V, 0); 
    vector<int>adj[V]; 
    vector<pair<int, int>>vec;
    for(auto it: edges){
        adj[it[0]].push_back(it[1]); 
        adj[it[1]].push_back(it[0]); 
    }
    int cnt = 0; 
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, adj, vis, vec, cnt); 
            cnt++; 
        }
    }
    vector<vector<int>>ans(cnt);
    for(int i = 0; i < V; i++){
        ans[vec[i].second].push_back(vec[i].first); 
    }
    return ans; 
}
