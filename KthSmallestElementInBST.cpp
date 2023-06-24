#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* f(TreeNode<int>* node, int &k){
    if(node == NULL) return NULL;
    TreeNode<int>* left = f(node->left, k);
    if(left != NULL) return left; 
    k--; 
    if(k == 0) return node;
    return f(node->right, k); 
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    return f(root, k)->data;
}
