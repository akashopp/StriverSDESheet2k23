#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int num = 0;
	for(int i = 0; i < n; i++){
		num ^= arr[i];
		num ^= (i+1);
	}	
	int rightBit = (num & ~(num - 1)); 
	int st = 0, notSt = 0;
	for(int i = 0; i < n; i++){
		if(arr[i]&rightBit) st ^= arr[i];
		else notSt ^= arr[i];
		if((i+1)&rightBit) st ^= (i+1);
		else notSt ^= (i+1);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) if(arr[i] == notSt) cnt++; 
	if(cnt == 2) return make_pair(st, notSt);
	return make_pair(notSt, st);
}
