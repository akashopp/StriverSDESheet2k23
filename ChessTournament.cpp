#include <bits/stdc++.h> 
bool isPossible(int dist, vector<int>& positions, int &n, int &c){
	int cnt = 1, ele = positions[0];
	for(int i = 1; i < n; i++){
		if(positions[i] - ele >= dist) cnt++, ele = positions[i]; 
	}
	return cnt >= c;
}
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(), positions.end());
	int low = 1, high = 1e9, ans = -1; 
	while(low <= high){
		int mid = low + (high - low)/2;
		if(isPossible(mid, positions, n, c)){
			ans = mid, low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	return ans;
}
