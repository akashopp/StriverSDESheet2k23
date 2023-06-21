#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	int cur1 = 1, cur2 = 1, maxi = INT_MIN; 
	for(int i = 0; i < n; i++){
		cur1 *= arr[i], cur2 *= arr[n-i-1]; 
		maxi = max({maxi, cur1, cur2});
		if(cur1 == 0) cur1 = 1; 
		if(cur2 == 0) cur2 = 1; 
	}
	return maxi; 
}
