#include<bits/stdc++.h>
void f(int i, int target, vector<int>& arr, vector<int>& cur, vector<vector<int>>& ans, int &n){
	if(target == 0){
		ans.push_back(cur);
		return;
	}
	for(int j = i; j < n; j++){
		if(j > i && arr[j] == arr[j-1]) continue;
		if(arr[j] > target) break;
		cur.push_back(arr[j]);
		f(j + 1, target - arr[j], arr, cur, ans, n);
		cur.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	vector<int>cur;
	vector<vector<int>>ans;
	sort(arr.begin(), arr.end());
	f(0, target, arr, cur, ans, n);
	return ans; 
}
