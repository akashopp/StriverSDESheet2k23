#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    unordered_map<int, int>mpp; 
    mpp[0] = 1;
    int cnt = 0, cur = 0; 
    for(auto it: arr){
        cur ^= it; 
        cnt += mpp[cur^x]; 
        mpp[cur]++; 
    }
    return cnt; 
}
