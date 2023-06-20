#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int num = 0; 
    for(auto &it: str){
        if(it >= '0' && it <= '9') num = num * 10 + (it - '0'); 
    }
    if(str[0] == '-') num = -num; 
    return num;
}
