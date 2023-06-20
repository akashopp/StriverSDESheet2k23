#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<pair<int, int>>adj[vertices];
    vector<int>dist(vertices, INT_MAX); 
    for(auto it: vec){
      adj[it[0]].push_back({it[1], it[2]});
      adj[it[1]].push_back({it[0], it[2]}); 
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    q.push({0, source}); 
    dist[source] = 0; 
    while(!q.empty()){
        int node = q.top().second, d = q.top().first;
        q.pop();
        for(auto it: adj[node]){
            int newNode = it.first, newDist = it.second; 
            if(d + newDist < dist[newNode]){
                dist[newNode] = d + newDist;
                q.push({dist[newNode], newNode}); 
            }
        }
    }
    return dist; 
}
