bool dfs(int node, vector<int>& vis, vector<int>adj[], bool flag){
	vis[node] = flag; 
	for(auto it: adj[node]){
		if(vis[it] == -1){
			if(!dfs(it, vis, adj, !flag)) return 0; 
		}else if(vis[it] == flag) return 0;
	}
	return 1;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n = edges.size(); 
	vector<int>adj[n], vis(n, -1); 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(edges[i][j]) adj[i].push_back(j), adj[j].push_back(i); 
		}
	}
	for(int i = 0; i < n; i++){
		if(vis[i] == -1){
			if(!dfs(i, vis, adj, 0)) return 0;
		}
	}
	return 1; 
}
