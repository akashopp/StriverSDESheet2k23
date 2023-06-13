#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<long long>st; 
	int mini;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
			mini = INT_MIN; 	
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			if(st.empty()){
				st.push(num);
				mini = num;	
			}else{
				if(num < mini){
					st.push(2 * 1LL * num - mini);
					mini = num; 
				}else{
					st.push(num); 
				}
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(st.empty()) return -1;
			long long x = st.top();
			if(x < mini){
				int temp = mini;
				mini = 2 * 1LL * mini - x; 
				x = temp;
			} 
			st.pop();
			return x;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(st.empty()) return -1;
			long long x = st.top(); 
			return x < mini ? mini : x; 
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(st.empty()) return -1; 
			return mini;
		}
};
