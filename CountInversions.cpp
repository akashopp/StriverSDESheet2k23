#include <bits/stdc++.h> 
long long merge(long long *arr, int low, int mid, int high){
    vector<int>temp; 
    int left = low, right = mid + 1; 
    long long ans = 0; 
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]) temp.push_back(arr[left++]); 
        else{
            ans += (mid - left + 1);
            temp.push_back(arr[right++]);
        }
    }
    while(left <= mid){
        temp.push_back(arr[left++]); 
    }
    while(right <= high){
        temp.push_back(arr[right++]); 
    }
    for(int i = low; i <= high; i++) arr[i] = temp[i - low]; 
    return ans; 
}
long long f(long long *arr, int low, int high){
    if(low == high) return 0; 
    int mid = (low + high)/2, cnt = 0; 
    cnt += f(arr, low, mid); 
    cnt += f(arr, mid + 1, high); 
    return cnt + merge(arr, low, mid, high);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    return f(arr, 0, n-1); 
}
