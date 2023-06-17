#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<pair<int, int>, int>>ans;
    vector<pair<int, int>>adj[n + 1]; 
    for(auto &it: g){
        adj[it.first.first].push_back({it.first.second, it.second}); 
        adj[it.first.second].push_back({it.first.first, it.second}); 
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq; 
    pq.push({0, {1, -1}}); 
    vector<bool>vis(n + 1, 0); 
    int cnt = 1; 
    while(!pq.empty()){
        int node = pq.top().second.first, par = pq.top().second.second, wt = pq.top().first; 
        pq.pop();
        if(vis[node]) continue; 
        if(par != -1) ans.push_back({{par, node}, wt});
        vis[node] = 1; 
        for(auto it: adj[node]){
            if(!vis[it.first]){
                pq.push({it.second, {it.first, node}}); 
            }
        }
    }
    return ans; 
}

