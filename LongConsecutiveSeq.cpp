#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int>st;
    int maxi = 0; 
    for(auto it: arr) st.insert(it); 
    for(auto it: arr){
        if(st.find(it - 1) == st.end()){
            int cnt = 0, temp = it; 
            while(st.find(temp) != st.end()) cnt++, temp++; 
            maxi = max(maxi, cnt); 
        }
    }
    return maxi; 
}
