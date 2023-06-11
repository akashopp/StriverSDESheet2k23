int f(vector<vector<int>>& matrix, int x){
    int n = matrix.size(), m = matrix[0].size(), ans = 0;
    for(int i = 0; i < n; i++){
        int low = 0, high = m-1, cnt = 0; 
        while(low <= high){
            int mid = low + (high - low)/2; 
            if(matrix[i][mid] <= x) low = mid + 1, cnt = mid + 1;
            else high = mid - 1;
        }
        ans += cnt; 
    }
    return ans;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low = 0, high = 1e9, n = matrix.size(), m = matrix[0].size(), ans; 
    while(low <= high){
        int mid = low + (high - low)/2; 
        int cnt = f(matrix, mid);
        if(cnt <= (n * m)/2) low = mid + 1;
        else ans = mid, high = mid - 1;
    }
    return ans;
}
