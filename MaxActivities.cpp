#include<bits/stdc++.h>
bool comp(vector<int>& v1, vector<int>& v2){
    if(v1[1] < v2[1]) return 1;
    else if(v1[1] > v2[1]) return 0;
    return v1[0] <= v2[0]; 
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n = start.size(), cnt = 0, x = -1e9; 
    vector<vector<int>>vec(n, vector<int>(2));
    for(int i = 0; i < n; i++) vec[i][0] = start[i], vec[i][1] = finish[i]; 
    sort(vec.begin(), vec.end(), comp); 
    for(int i = 0; i < n; i++){
        if(x <= vec[i][0]) cnt++, x = vec[i][1];
    }
    return cnt; 
}
