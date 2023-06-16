#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<long>dist(n+1, 1e9); 
    dist[src] = 0;
    for(int i = 0; i < n-1; i++){
        for(auto &it: edges){
            if(dist[it[0]] != 1e9 && dist[it[0]] + it[2] < dist[it[1]]){
                dist[it[1]] = dist[it[0]] + it[2];
            }
        }
    }
    return dist[dest];
}
