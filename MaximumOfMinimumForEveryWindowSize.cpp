#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    stack<int>st; 
    int prev[n], next[n];
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(st.empty()) prev[i] = -1;
        else prev[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(st.empty()) next[i] = n;
        else next[i] = st.top();
        st.push(i);
    }
    vector<int>ans(n + 1, INT_MIN);
    for(int i = 0; i < n; i++){
        int dist = next[i] - prev[i] - 1;
        ans[dist] = max(ans[dist], a[i]);
    }
    for(int i = n-1; i >= 0; i--) ans[i] = max(ans[i], ans[i+1]);
    vector<int>res(n);
    for(int i = 0; i < n; i++) res[i] = ans[i+1];
    return res;
}
