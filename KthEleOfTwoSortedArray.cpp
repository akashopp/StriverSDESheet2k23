int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    int low = 0, high = 1e9, ans = 0; 
    while(low <= high){
        int mid = low + (high - low)/2;
        int l = 0, h = m-1, cnt1 = 0, cnt2 = 0; 
        while(l <= h){
            int mi = l + (h - l)/2; 
            if(row1[mi] <= mid) cnt1 = mi + 1, l = mi + 1;
            else h = mi - 1;
        }
        l = 0, h = n-1; 
        while(l <= h){
            int mi = l + (h - l)/2;
            if(row2[mi] <= mid) cnt2 = mi + 1, l = mi + 1;
            else h = mi - 1;
        }
        if(cnt1 + cnt2 >= k) ans = mid, high = mid - 1; 
        else low = mid + 1; 
    }
    return ans;
}
