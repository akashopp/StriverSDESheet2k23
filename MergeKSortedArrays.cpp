#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q; 
    int n = kArrays.size();
    for(int i = 0; i < n; i++) q.push({kArrays[i][0], i}); 
    vector<int>ans, sz(n, 0); 
    while(!q.empty()){
        int ele = q.top().first, num = q.top().second;
        q.pop(); 
        ans.push_back(ele); 
        sz[num]++;
        if(sz[num] < kArrays[num].size()) q.push({kArrays[num][sz[num]], num}); 
    }
    return ans;
}
