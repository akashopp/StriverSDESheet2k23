#include <bits/stdc++.h> 
void f(string &s, vector<bool>& vis, string &cur, vector<string>& ans, int n){
    if(cur.size() == n){
        ans.push_back(cur);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            cur += s[i], vis[i] = 1;
            f(s, vis, cur, ans, n);
            cur.pop_back(), vis[i] = 0; 
        }
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    int n = s.size();
    vector<bool>vis(n);
    string cur;  
    vector<string>ans;
    f(s, vis, cur, ans, n);
    return ans;
}
