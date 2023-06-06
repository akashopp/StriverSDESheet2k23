void f(int i, int k, vector<int>& cur, vector<vector<int>>& ans, vector<int>& arr, int &n){
    if(i == n){
        if(k == 0){
            ans.push_back(cur);
        }
        return;
    }
    f(i+1, k, cur, ans, arr, n);
    cur.push_back(arr[i]);
    f(i+1, k - arr[i], cur, ans, arr, n);
    cur.pop_back(); 
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int>cur; 
    vector<vector<int>>ans;
    f(0, k, cur, ans, arr, n);
    return ans; 
}
