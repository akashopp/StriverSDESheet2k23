#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(), arr.end()); 
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int low = j+1, high = n-1; 
            while(low < high){
                if(arr[i] + arr[j] + arr[low] + arr[high] == target) return "Yes";
                else if(arr[i] + arr[j] + arr[low] + arr[high] < target) low++; 
                else high--; 
            }
        }
    }
    return "No"; 
}
