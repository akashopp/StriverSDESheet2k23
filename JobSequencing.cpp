#include <bits/stdc++.h> 
bool comp(vector<int>& v1, vector<int>& v2){
    return v1[1] >= v2[1]; 
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(), jobs.end(), comp);
    int maxi = 0, n = jobs.size(); 
    vector<bool>vis(3001, 0);
    for(int i = 0; i < n; i++){
        int ind = jobs[i][0];
        while(ind > 0 && vis[ind]) ind--;
        if(ind > 0) maxi += jobs[i][1], vis[ind] = 1; 
    }
    return maxi; 
}
