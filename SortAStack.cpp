#include <bits/stdc++.h> 
void insert(stack<int>& st, int temp){
	if(st.size() == 0 || st.top() <= temp){
		st.push(temp); 
		return;
	}
	int topEle = st.top(); 
	st.pop(); 
	insert(st, temp); 
	st.push(topEle); 
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.size() == 1) return; 
	int temp = stack.top(); 
	stack.pop(); 
	sortStack(stack); 
	insert(stack, temp); 
}
