#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int cnt = 0, n = 9; 
    vector<int>currency = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    for(int i = n-1; i >= 0; i--){
        if(amount >= currency[i]) cnt += amount/currency[i], amount = amount%currency[i];
    }
    return cnt; 
}
