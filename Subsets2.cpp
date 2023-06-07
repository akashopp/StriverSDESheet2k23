#include <bits/stdc++.h> 
void f(int i, vector<int>& arr, vector<int>& cur, int n, set<vector<int>>& st){
    if(i == n){
        st.insert(cur); 
        return;
    }
    cur.push_back(arr[i]); 
    f(i+1, arr, cur, n, st); 
    cur.pop_back();                                                    
    f(i+1, arr, cur, n, st); 
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<int>cur; 
    set<vector<int>>st; 
    sort(arr.begin(), arr.end());
    f(0, arr, cur, n, st); 
    vector<vector<int>>ans; 
    for(auto it: st) ans.push_back(it);
    return ans; 
}
