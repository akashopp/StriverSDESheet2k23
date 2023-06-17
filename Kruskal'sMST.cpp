#include <bits/stdc++.h> 
class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }
    int par(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = par(parent[node]); 
    }
    void uni(int u, int v) {
        int ulp_u = par(u); 
        int ulp_v = par(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
bool comp(vector<int>& v1, vector<int>& v2){
	return (v1[2] <= v2[2]); 
}
int f(vector<vector<int>>& graph, int n){
	DisjointSet ds(n);
	int ans = 0; 
	for(auto &it: graph){
		if(ds.par(it[0]) != ds.par(it[1])){
			ds.uni(it[0], it[1]); 
			ans += it[2];
		}
	}
	return ans; 
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
	sort(graph.begin(), graph.end(), comp); 
	return f(graph, n); 
}
