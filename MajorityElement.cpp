#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int cnt = 0, ele = -1e9;
	for(int i = 0; i < n; i++){
		if(cnt == 0) ele = arr[i];
		if(arr[i] == ele) cnt++;
		else cnt--; 
	}
	cnt = 0;
	for(int i = 0; i < n; i++) if(arr[i] == ele) cnt++;
	return (cnt > n/2 ? ele : -1); 
}
