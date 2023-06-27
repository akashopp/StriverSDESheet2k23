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
void inorder(BinaryTreeNode<int>* node, vector<int>& vec){
    if(node == NULL) return;
    inorder(node->left, vec); 
    vec.push_back(node->data); 
    inorder(node->right, vec); 
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<int>vec; 
    inorder(root, vec); 
    for(int i = 1; i < vec.size(); i++){
        if(vec[i] < vec[i-1]) return 0;
    }
    return 1;
}
