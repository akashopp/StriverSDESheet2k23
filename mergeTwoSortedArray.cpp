#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int n, int m) {
	// Write your code here.
	int i = n-1, j = m-1, k = n + m - 1; 
	while(i >= 0 && j >= 0){
		if(arr1[i] > arr2[j]) arr1[k--] = arr1[i--];
		else arr1[k--] = arr2[j--];
	}
	while(j >= 0) arr1[k--] = arr2[j--]; 
	return arr1; 
}
