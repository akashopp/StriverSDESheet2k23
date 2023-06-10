string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = "";
    int m = arr[0].size();
    for(int i = 0; i < m; i++){
        bool flag = 1; 
        for(int j = 0; j < n; j++){
            if(arr[j][i] != arr[0][i]){
                flag = 0;
                break;
            }
        }
        if(flag) ans += arr[0][i]; 
        else break;
    }
    return ans; 
}
