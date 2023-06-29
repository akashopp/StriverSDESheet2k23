int cutLogs(int k, int n)
{
    // Write your code here.
    int dp[k+1] = {0}, ans = 0;
    while(dp[k] < n){
        ans++;
        for(int ind = k; ind > 0; ind--) dp[ind] += 1 + dp[ind - 1];
    }
    return ans;
}
