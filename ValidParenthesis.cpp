bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>st; 
    for(auto it: expression){
        if(it == '(' || it == '{' || it == '[') st.push(it);
        else{
            if(!st.empty()){
                if(it == ')' && st.top() == '(') st.pop();
                else if(it == '}' && st.top() == '{') st.pop();
                else if(it == ']' && st.top() == '[') st.pop();
                else return 0; 
            }else return 0;
        }
    }
    return (st.empty());
}
