#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    int n = price.size();
    stack<pair<int, int>>st;
    vector<int>ans(n);
    for(int i = 0; i < n; i++){
        int cnt = 1; 
        while(!st.empty() && st.top().first <= price[i]) cnt += st.top().second, st.pop();
        ans[i] = cnt; 
        st.push({price[i], cnt});
    }
    return ans;
}
