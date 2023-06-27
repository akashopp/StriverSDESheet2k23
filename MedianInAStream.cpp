#include<bits/stdc++.h>
void balance(priority_queue<int>&p1, priority_queue<int, vector<int>, greater<int>>&p2){
	if(p1.size() > p2.size() && p1.size() - p2.size() == 2){
		p2.push(p1.top()); 
		p1.pop(); 
	}else if(p2.size() > p1.size() && p2.size() - p1.size() == 2){
		p1.push(p2.top()); 
		p2.pop(); 
	}
}
vector<int> findMedian(vector<int> &arr, int n){
	// Write your code here 
	vector<int>ans(n);
	priority_queue<int>p1;
	priority_queue<int, vector<int>, greater<int>>p2; 
	for(int i = 0; i < n; i++){
		if(!p2.empty() && p2.top() < arr[i]) p2.push(arr[i]);
		else p1.push(arr[i]); 
		balance(p1, p2); 
		if(p1.size() == p2.size()) ans[i] = (p1.top() + p2.top())/2;
		else ans[i] = (p1.size() > p2.size()) ? p1.top() : p2.top(); 
	}
	return ans;
}
