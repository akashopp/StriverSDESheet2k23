#include <bits/stdc++.h> 
int f1(vector<int> &arr, int low, int mid, int high){
	int ans = 0, right = mid + 1; 
	for(int i = low; i <= mid; i++){
		while(right <= high && arr[i] > arr[right] * 2) right++; 
		ans += right - (mid + 1);
	}
	return ans;
}
void merge(vector<int> &arr, int low, int mid, int high){
	int left = low, right = mid + 1; 
	vector<int>temp; 
	while(left <= mid && right <= high){	
		if(arr[left] <= arr[right]){
			temp.push_back(arr[left++]);
		}else{
			temp.push_back(arr[right++]); 
		}
	}
	while(left <= mid) temp.push_back(arr[left++]); 
	while(right <= high) temp.push_back(arr[right++]); 
	for(int i = low; i <= high; i++) arr[i] = temp[i - low];
}
int f(vector<int> &arr, int low, int high){
	if(low == high) return 0; 
	int mid = (low + high)/2, cnt = 0; 
	cnt += f(arr, low, mid); 
	cnt += f(arr, mid + 1, high); 
	cnt += f1(arr, low, mid, high); 
	merge(arr, low, mid, high); 
	return cnt; 
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	return f(arr, 0, n-1);
}
