#include <bits/stdc++.h> 
bool isPali(int i, int j, string &s){
    while(i < j){
        if(s[i] != s[j]) return 0;
        i++, j--;
    }
    return 1;
}
void f(int i, int j, vector<string>& cur, vector<vector<string>>& ans, int &n, string &s, string ds){
    if(j == n){
        if(i == n) ans.push_back(cur);
        return;
    }
    ds += s[j];
    f(i, j+1, cur, ans, n, s, ds);
    if(isPali(i, j, s)){
        cur.push_back(ds);
        f(j+1, j+1, cur, ans, n, s, "");
        cur.pop_back();
    }
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    int n = s.size();
    vector<string>cur;
    vector<vector<string>>ans;
    f(0, 0, cur, ans, n, s, "");
    return ans;
}
