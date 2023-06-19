#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int>ans;
    if(root == NULL) return ans;
    queue<pair<int, BinaryTreeNode<int>*>>q; 
    q.push({0, root}); 
    map<int, int>mpp; 
    while(!q.empty()){
        int level = q.front().first;
        BinaryTreeNode<int>* node = q.front().second;
        q.pop();
        mpp[level] = node->data;
        if(node->left != NULL) q.push({level - 1, node->left}); 
        if(node->right != NULL) q.push({level + 1, node->right});
    }
    for(auto &it: mpp) ans.push_back(it.second);
    return ans;
}
