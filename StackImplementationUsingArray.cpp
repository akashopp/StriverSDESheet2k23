#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int *arr; 
public:
    int t, capacity; 
    Stack(int capacity) {
        // Write your code here.
        this->capacity = capacity; 
        arr = new int[capacity]; 
        t = -1;
    }

    void push(int num) {
        // Write your code here.
        if(t < capacity) arr[++t] = num; 
    }

    int pop() {
        // Write your code here.
        return t == -1 ? -1 : arr[t--]; 
    }
    
    int top() {
        // Write your code here.
        return t == -1 ? -1 : arr[t]; 
    }
    
    int isEmpty() {
        // Write your code here.
        return (t == -1); 
    }
    
    int isFull() {
        // Write your code here.
        return (t == capacity); 
    }
    
};
