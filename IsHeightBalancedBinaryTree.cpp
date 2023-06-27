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
int f(BinaryTreeNode<int>* node){
    if(node == NULL) return 0;
    int left = 1 + f(node->left); 
    int right = 1 + f(node->right); 
    if(left < 0 || right < 0) return -1e9; 
    if(abs(left - right) > 1) return -1e9; 
    return max(left, right); 
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return f(root) < 0 ? 0 : 1; 
}
