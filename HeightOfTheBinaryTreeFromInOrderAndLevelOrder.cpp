#include <bits/stdc++.h> 
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int n){
	// Write your code here.
	unordered_map<int, int>mpp;
	int maxi = 0; 
	for(int i = 0; i < n; i++) mpp[inorder[i]] = i;
	queue<pair<int, pair<int, int>>>q;
	q.push({0, {0, n-1}});
	for(int i = 0; i < n; i++){
		auto it = q.front();
		q.pop();
		maxi = max(maxi, it.first);
		int ind = mpp[levelOrder[i]];
		if(ind - 1 >= it.second.first) q.push({it.first + 1, {it.second.first, ind - 1}});
		if(ind + 1 <= it.second.second) q.push({it.first + 1, {ind + 1, it.second.second}});
	}
	return maxi;
}
