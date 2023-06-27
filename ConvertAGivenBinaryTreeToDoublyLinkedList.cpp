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
void f(BinaryTreeNode<int>* node, BinaryTreeNode<int>* &root, BinaryTreeNode<int>* prev){
    if(node == NULL) return;
    f(node->left, root, prev); 
    if(root == NULL) root = node; 
    else{
        node->left = prev; 
        prev->right = node;
    }
    prev = node;
    f(node->right, root, node); 
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* prev = NULL, * r = NULL;
    f(root, r, prev);
    return r;
}
