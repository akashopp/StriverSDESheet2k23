#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int>q;
    int n; 
   public:
    Stack() {
        // Implement the Constructor.
        n = 0; 
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return n; 
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return (n == 0);
    }

    void push(int element) {
        // Implement the push() function.
        n++, q.push(element); 
        for(int i = 0; i < n-1; i++){
            q.push(q.front()); 
            q.pop(); 
        }
    }

    int pop() {
        // Implement the pop() function.
        if(n == 0) return -1; 
        int ele = q.front();
        q.pop();
        n--; 
        return ele;
    }

    int top() {
        // Implement the top() function.
        if(n == 0) return -1; 
        return q.front(); 
    }
};
