#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size(), ans = 0, maxi = -1e9;
    for(int i = n-1; i >= 0; i--){
        ans = max(ans, maxi - prices[i]);
        maxi = max(maxi, prices[i]);
    }
    return ans;
}
