#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int>indegree(n+1, 0); 
  queue<int>q; 
  vector<int>adj[n+1]; 
  for(auto &it: edges){
    adj[it.first].push_back(it.second); 
    indegree[it.second]++;
  }
  for(int i = 1; i <= n; i++) if(indegree[i] == 0) q.push(i); 
  int cnt = 0; 
  while(!q.empty()){
    int node = q.front(); 
    q.pop(); 
    cnt++; 
    for(auto &it: adj[node]){
      indegree[it]--; 
      if(indegree[it] == 0) q.push(it); 
    }
  }
  return cnt != n; 
}
