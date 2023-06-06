#include<bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at, at + n);
    sort(dt, dt + n);
    int maxi = 1, cur = 1, low = 0, high = 1;
    while(high < n){
        if(at[high] <= dt[low]){
            cur++;
            high++;
        }else{
            cur--;
            low++; 
        }
        maxi = max(maxi, cur); 
    }
    return maxi;
}
