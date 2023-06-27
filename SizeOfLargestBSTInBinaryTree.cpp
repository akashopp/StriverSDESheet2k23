#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
class Node{
public:
    int mini, maxi, msize; 
    Node(int mn, int mx, int ms){
        mini = mn;
        maxi = mx; 
        msize = ms; 
    }
};
Node f(TreeNode<int>* node){
    if(!node){
        return Node(INT_MAX, INT_MIN, 0);
    }
    auto left = f(node->left);
    auto right = f(node->right);
    if(node->data > left.maxi && node->data < right.mini){
        return Node(min(node->data, left.mini), max(node->data, right.maxi), left.msize + right.msize + 1); 
    }
    return Node(INT_MIN, INT_MAX, max(right.msize, left.msize)); 
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return f(root).msize; 
}
