 #include<stack>
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
    stack<int>st; 
    int n = heights.size(), maxi = 0;
    vector<int>leftSmaller(n), rightSmaller(n);
    for(int i = 0; i < n; i++){
      while(!st.empty() && heights[st.top()] >= heights[i]) st.pop(); 
      if(st.empty()) leftSmaller[i] = 0;
      else leftSmaller[i] = st.top() + 1; 
      st.push(i);
    }
    while(!st.empty()) st.pop(); 
    for(int i = n-1; i >= 0; i--){
      while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
      if(st.empty()) rightSmaller[i] = n-1;
      else rightSmaller[i] = st.top() - 1; 
      st.push(i); 
      maxi = max(maxi, (rightSmaller[i] - leftSmaller[i] + 1) * heights[i]); 
    }
    return maxi; 
 }
