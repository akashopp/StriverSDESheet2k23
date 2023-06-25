#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    BinaryTreeNode<int>* node = root;
    pair<int, int>p = {-1, -1};
    while(node != NULL){
        if(node->data >= key) node = node->left;
        else{
            p.first = node->data;
            node = node->right; 
        }
    }
    node = root;
    while(node != NULL){
        if(node->data <= key) node = node->right;
        else{
            p.second = node->data;
            node = node->left; 
        }
    }
    return p; 
}
