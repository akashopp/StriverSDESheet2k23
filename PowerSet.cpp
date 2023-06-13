#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    int n = v.size(), x = (1 << n);
    vector<vector<int>>ans;
    for(int i = 0; i < x; i++){
        vector<int>temp; 
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) temp.push_back(v[j]);
        }
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    return ans; 
}
