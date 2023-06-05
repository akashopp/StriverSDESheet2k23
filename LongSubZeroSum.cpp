#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int low = 0, maxi = 0, n = input.size();
    unordered_set<char>st; 
    for(int i = 0; i < n; i++){
        if(st.find(input[i]) == st.end()){
            st.insert(input[i]);
        }else{
            while(input[low] != input[i]) st.erase(input[low++]); 
            low++; 
        }
        maxi = max(maxi, i - low + 1);
    }
    return maxi; 
}
