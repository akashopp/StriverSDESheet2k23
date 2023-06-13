#include <bits/stdc++.h> 
class Queue {
    int *arr, f, b;
public:
    Queue() {
        // Implement the Constructor
        arr = new int[10000],  f = b = 0; 
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return (f == b); 
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr[b++] = data; 
    }

    int dequeue() {
        // Implement the dequeue() function
        return f == b ? -1 : arr[f++]; 
    }

    int front() {
        // Implement the front() function
        return f == b ? -1 : arr[f]; 
    }
};
