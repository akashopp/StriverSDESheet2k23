#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int>vis(51, 0), ans;
    for(int i = 0; i < n; i++){
        if(q[i][0] == 0) vis[q[i][1]]++;
        else{
            for(int ind = 1; ind <= 50; ind++){
                if(vis[ind]){
                    vis[ind]--;
                    ans.push_back(ind);
                    break;
                }
            }
        }
    }
    return ans;
}
