#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    deque<int>q;
    int n = nums.size();
    vector<int>ans; 
    for(int i = 0; i < n; i++){
        if(!q.empty() && q.front() == i - k) q.pop_front();
        while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
        q.push_back(i);
        if(i >= k - 1) ans.push_back(nums[q.front()]); 
    }
    return ans; 
}
