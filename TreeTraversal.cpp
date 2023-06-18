#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    stack<pair<BinaryTreeNode<int>* , int>>st; 
    vector<vector<int>>ans(3); 
    if(root == NULL) return ans;
    st.push({root, 1}); 
    while(!st.empty()){
        BinaryTreeNode<int>* node = st.top().first;
        int num = st.top().second; 
        st.pop();
        if(num == 1){
            ans[1].push_back(node->data); 
            st.push({node, num + 1}); 
            if(node->left != NULL) st.push({node->left, 1}); 
        }else if(num == 2){
            ans[0].push_back(node->data); 
            st.push({node, num + 1}); 
            if(node->right != NULL) st.push({node->right, 1}); 
        }else{
            ans[2].push_back(node->data); 
        }
    }
    return ans;
}
