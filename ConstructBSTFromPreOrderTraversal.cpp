#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* f(int &i, vector<int>& preOrder, int &n, int lim){
    if(i == n || preOrder[i] > lim) return NULL;
    TreeNode<int>* node = new TreeNode<int>(preOrder[i]);
    i++;
    node->left = f(i, preOrder, n, node->data);
    node->right = f(i, preOrder, n, lim);
    return node;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i = 0, n = preOrder.size();
    return f(i, preOrder, n, INT_MAX);
}
