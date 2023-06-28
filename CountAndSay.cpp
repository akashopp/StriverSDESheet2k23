#include <bits/stdc++.h> 
string solve(int n){
	if(n == 1) return "1";
	string temp = solve(n-1), res = "";
	int cnt = 1, prev = temp[0], sz = temp.size();
	for(int i = 1; i < sz; i++){
		if(temp[i] == prev) cnt++;
		else{
			res += cnt + '0';
			res += prev;
			prev = temp[i];
			cnt = 1;
		}
	}
	res += cnt + '0';
	res += prev; 
	return res;
}
string writeAsYouSpeak(int n) 
{
	// Write your code here.	
	return solve(n);
}
