#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int>ans; 
    if(root == NULL) return ans;
    queue<BinaryTreeNode<int>*>q; 
    q.push(root); 
    bool flag = 0; 
    while(!q.empty()){
        int n = q.size();
        vector<int>vec(n); 
        for(int i = 0; i < n; i++){
            BinaryTreeNode<int>* node = q.front(); 
            q.pop(); 
            if(flag) vec[n - i - 1] = node->data; 
            else vec[i] = node->data; 
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right); 
        }
        for(auto &it: vec) ans.push_back(it); 
        flag = !flag; 
    }
    return ans;
}
