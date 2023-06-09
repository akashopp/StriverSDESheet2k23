bool dfs(int node, vector<int>adj[], vector<bool>vis){
  vis[node] = 1; 
  for(auto it: adj[node]){
    if(!vis[it]) return dfs(it, adj, vis); 
    else return 1; 
  }
  return 0; 
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int>adj[n + 1]; 
  for(auto it: edges){
    adj[it.first].push_back(it.second);
  }
  vector<bool>vis(n+1, 0); 
  for(int i = 1; i <= n; i++){
    if(!vis[i]){
      if(dfs(i, adj, vis)) return 1; 
    }
  }
  return 0; 
}
