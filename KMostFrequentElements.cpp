#include <bits/stdc++.h> 
bool comp(pair<int, int>& p1, pair<int, int>& p2){
    if(p1.first < p2.first) return 1;
    if(p1.first > p2.first) return 0; 
    return p1.second >= p2.second; 
}
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<int>ans; 
    vector<pair<int, int>>vec; 
    int cnt = 0, val = arr[0]; 
    for(auto it: arr){
        if(val == it) cnt++;
        else vec.push_back({cnt, val}), cnt = 1, val = it; 
    }
    vec.push_back({cnt, val}); 
    sort(vec.begin(), vec.end(), comp); 
    n = vec.size(); 
    for(int i = n-1; i >= n-k; i--){
       ans.push_back(vec[i].second); 
    }
    sort(ans.begin(), ans.end()); 
    return ans; 
}
