#include <bits/stdc++.h> 
class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq; 
    int k; 
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       this->k = k; 
       for(auto &it: arr) pq.push(it); 
       while(pq.size() != k) pq.pop(); 
    }

    void add(int num) {
        // Write your code here.
        if(num > pq.top()){
            pq.push(num);
            pq.pop(); 
        }
    }

    int getKthLargest() {
       // Write your code here.
       return pq.top(); 
    }

};
