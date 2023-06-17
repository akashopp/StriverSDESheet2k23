#include<stack>
void dfs(int node, stack<int>& st, vector<int>adj[], vector<bool>& vis, bool flag, vector<int>& vec){
    if(flag) vis[node] = 1;
    else vis[node] = 0, vec.push_back(node);
    for(auto it: adj[node]){
        if(flag && !vis[it]) dfs(it, st, adj, vis, flag, vec);
        else if(!flag && vis[it]) dfs(it, st, adj, vis, flag, vec);
    }
    if(flag) st.push(node); 
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    stack<int>st; 
    vector<vector<int>>ans; 
    vector<bool>vis(n, 0);
    vector<int>adj[n], adjR[n], v;
    for(auto &it: edges){
        adj[it[0]].push_back(it[1]);
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]) dfs(i, st, adj, vis, 1, v);
    }
    for(auto &it: edges){
        adjR[it[1]].push_back(it[0]); 
    }
    while(!st.empty()){
        int node = st.top(); 
        if(vis[node]){
            vector<int>temp;
            dfs(node, st, adjR, vis, 0, temp); 
            ans.push_back(temp); 
        }
        st.pop(); 
    }
    return ans; 
}
