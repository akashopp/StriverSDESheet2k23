#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
TreeNode<int>* f(TreeNode<int>* node, int &k){
    if(node == NULL) return NULL;
    TreeNode<int>* right = f(node->right, k);
    if(right != NULL) return right; 
    k--; 
    if(k == 0) return node; 
    return f(node->left, k);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    TreeNode<int>* node = f(root, k);
    return node == NULL ? -1 : node->data;
}
