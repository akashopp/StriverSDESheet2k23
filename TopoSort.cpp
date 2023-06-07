#include <bits/stdc++.h> 
void dfs(int node, vector<int>adj[], vector<bool>& vis, stack<int>& st){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]) dfs(it, adj, vis, st);
    }
    st.push(node); 
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<bool>vis(v, 0);
    vector<int>adj[v], ans;
    stack<int>st;
    for(auto it: edges) adj[it[0]].push_back(it[1]); 
    for(int i = 0; i < v; i++){
        if(!vis[i]) dfs(i, adj, vis, st); 
    }
    while(!st.empty()) ans.push_back(st.top()), st.pop();
    return ans;
}
