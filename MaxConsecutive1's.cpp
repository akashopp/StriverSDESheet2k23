int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int low = 0, high = 0, cnt = 0, maxi = 0;
    while(high < n){
        if(arr[high] == 0) cnt++;
        while(cnt > k) cnt = cnt - (arr[low] == 0), low++;
        maxi = max(maxi, high - low + 1);
        high++; 
    }
    return maxi; 
}
