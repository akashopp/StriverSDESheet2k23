#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    // Write your code here
    int i = 0, j = 0, n = a.size(), m = b.size();
    long long temp1 = 0, temp2 = 0;
    while(i < n || j < m){
        while(i < n && a[i] != '.') temp1 = temp1*10 + (a[i] - '0'), i++; 
        while(j < m && b[j] != '.') temp2 = temp2*10 + (b[j] - '0'), j++;
        if(temp1 > temp2) return 1;
        else if(temp1 < temp2) return -1;
        temp1 = temp2 = 0; 
        i++, j++; 
    }
    return 0; 
}
