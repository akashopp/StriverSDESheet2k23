#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int getLeft(BinaryTreeNode<int>* node){
    return node->left == NULL ? 0 : node->left->data; 
}
int getRight(BinaryTreeNode<int>* node){
    return node->right == NULL ? 0 : node->right->data;
}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;
    if(getLeft(root) + getRight(root) <= root->data){
        if(root->left != NULL) root->left->data = root->data;
        if(root->right != NULL) root->right->data = root->data; 
    }
    changeTree(root->left);
    changeTree(root->right); 
    root->data = getLeft(root) + getRight(root); 
}  
