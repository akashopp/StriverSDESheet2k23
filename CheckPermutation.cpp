#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    vector<int>v1(26, 0), v2(26, 0); 
    for(auto &it: str1) v1[it - 'a']++;
    for(auto &it: str2) v2[it - 'a']++; 
    for(int i = 0; i < 26; i++){
        if(v1[i] != v2[i]) return 0;
    }
    return 1; 
}
