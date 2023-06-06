#include <bits/stdc++.h> 
bool comp(vector<int>& v1, vector<int>& v2){
    if(v1[1] < v2[1]) return 1; 
    else if(v1[1] > v2[1]) return 0;
    return (v1[2] < v2[2]); 
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    vector<vector<int>>vec(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        vec[i][0] = start[i];
        vec[i][1] = end[i];
        vec[i][2] = i;
    }
    sort(vec.begin(), vec.end(), comp);
    vector<int>ans; 
    int x = -1e9; 
    for(int i = 0; i < n; i++){
        if(x < vec[i][0]){
            x = vec[i][1];
            ans.push_back(vec[i][2] + 1);
        }
    }
    return ans;
}
