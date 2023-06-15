#include<bits/stdc++.h>
string reverseString(string &str){
	// Write your code here.	
	stack<string>st; 
	string temp, ans; 
	str += ' ';
	for(auto it: str){
		if(it == ' '){
			if(temp.size() > 0) st.push(temp);
			temp = "";
		}else temp += it;
	}
	while(!st.empty()){
		ans += st.top() + ' ';
		st.pop();
	}
	return ans; 
}
