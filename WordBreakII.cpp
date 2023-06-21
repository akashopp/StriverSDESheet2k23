#include <bits/stdc++.h> 
void f(string s, string ds, unordered_set<string>& mpp, vector<string>& ans){
    if(s.empty()){
        ds.pop_back();
        ans.push_back(ds); 
        return;
    }
    int n = s.size();
    for(int i = 1; i <= n; i++){
        if(mpp.find(s.substr(0, i)) != mpp.end()){
            f(s.substr(i), ds + s.substr(0, i) + " ", mpp, ans);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    unordered_set<string>mpp;
    mpp.insert(dictionary.begin(), dictionary.end());
    vector<string>ans;
    f(s, "", mpp, ans);
    return ans;
}
