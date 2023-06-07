#include <bits/stdc++.h> 
bool comp(pair<int, int>& p1, pair<int, int>& p2){
    return (p1.second*1.00/p1.first > p2.second*1.00/p2.first);
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    double ans = 0.0;
    int sum = 0; 
    sort(items.begin(), items.end(), comp);
    // for(auto it: items) cout<<it.first<<' '<<it.second<<endl; 
    for(auto it: items){
        if(sum + it.first <= w) sum += it.first, ans += it.second;
        else{
            ans += (w - sum)*1.00*it.second/it.first;
            break;
        }
    }
    return ans; 
}
