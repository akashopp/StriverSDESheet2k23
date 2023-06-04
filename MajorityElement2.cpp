#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0, n = arr.size();
    for(auto it: arr){
        if(it == num1) cnt1++;
        else if(it == num2) cnt2++;
        else if(cnt1 == 0) num1 = it, cnt1 = 1;
        else if(cnt2 == 0) num2 = it, cnt2 = 1;
        else cnt1--, cnt2--;
    }
    cnt1 = 0, cnt2 = 0;
    for(auto it: arr){
        if(it == num1) cnt1++;
        else if(it == num2) cnt2++;
    }
    vector<int>vec;
    if(cnt1 > n/3) vec.push_back(num1);
    if(cnt2 > n/3) vec.push_back(num2);
    return vec;
}
