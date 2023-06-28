#include <bits/stdc++.h> 
void lps(string &p, vector<int> &vec, int &n){
    vec[0] = 0; 
    int i = 0, j = 1; 
    while(j < n){
        if(p[i] == p[j]){
            vec[j++] = ++i; 
        }else{
            if(i){
                i = vec[i-1];
            }else{
                vec[j++] = 0;
            }
        }
    }
}
bool findPattern(string p, string s)
{
    // Write your code here.
    int n = p.size(), m = s.size();
    vector<int>vec(n);
    lps(p, vec, n); 
    int i = 0, j = 0; 
    while(j < m){
        if(s[j] == p[i]) i++, j++;
        if(i == n) return 1;
        else if(j < m && s[j] != p[i]){
            if(i) i = vec[i-1];
            else j++; 
        }
    }
    return 0;    
}
