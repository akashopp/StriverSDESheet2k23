#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int n = arr.size(), cur = 0, maxi = 0;
  unordered_map<int, int>mpp;
  for(int i = 0; i < n; i++){
    cur += arr[i]; 
    if(cur == 0) maxi = i + 1; 
    else if(mpp.find(cur) == mpp.end()) mpp[cur] = i; 
    else{
      maxi = max(maxi, i - mpp[cur]); 
    }
  }
  return maxi; 
}
