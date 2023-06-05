#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	unordered_map<int, int>mpp;
    vector<int>vec; 
    int low = 0, n = arr.size(), cnt = 0; 
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]] == 1) cnt++;
        if(i - low + 1 == k){
            vec.push_back(cnt);
            mpp[arr[low]]--;
            if(mpp[arr[low]] == 0) cnt--; 
            low++; 
        }
    }
    return vec;
}
