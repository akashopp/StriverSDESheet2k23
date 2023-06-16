#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<bool>vis(vertex, 0);
    queue<int>q; 
    vector<int>ans; 
    vector<set<int>>adj(vertex); 
    for(auto it: edges) adj[it.first].insert(it.second), adj[it.second].insert(it.first);
    for(int i = 0; i < vertex; i++){
        if(!vis[i]){
            ans.push_back(i);
            vis[i] = 1;
            q.push(i); 
            while(!q.empty()){
                int node = q.front();
                q.pop(); 
                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it); 
                        ans.push_back(it); 
                    }
                }
            }
        }
    }
    return ans;
}
