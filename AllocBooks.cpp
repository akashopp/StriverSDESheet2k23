#include <bits/stdc++.h> 
bool f(long long x, int n, vector<int>& time){
	long long sum = 0;
	int cnt = 1;  
	for(auto it: time){
		if(it > x) return 0; 
		if(sum + it > x) cnt++, sum = 0;
		sum += it; 
	}
	return (cnt <= n);
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long low = 1, high = 1e12, ans = -1; 
	while(low <= high){
		long long mid = (low + high)>>1;
		if(f(mid, n, time)) ans = mid, high = mid - 1; 
		else low = mid + 1;
	}
	return ans;
}
