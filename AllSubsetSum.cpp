#include <bits/stdc++.h> 
void f(int i, int sum, vector<int>& num, int n, vector<int>& ans){
    if(i == n){
        ans.push_back(sum); 
        return;
    }
    f(i+1, sum, num, n, ans);
    f(i+1, sum + num[i], num, n, ans); 
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    int n = num.size(); 
    vector<int>ans; 
    f(0, 0, num, n, ans); 
    sort(ans.begin(), ans.end()); 
    return ans; 
}
