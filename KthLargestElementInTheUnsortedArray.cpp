#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	priority_queue<int>pq; 
	for(auto &it: arr) pq.push(it); 
	int ind = 1; 
	while(ind < K) pq.pop(), ind++; 
	return pq.top(); 
}
