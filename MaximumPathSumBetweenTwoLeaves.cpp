#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long f(TreeNode<int>* node, long long &maxi){
    if(node == NULL) return -1e9;
    if(!node->left && !node->right) return node->val;
    long long left = f(node->left, maxi);
    long long right = f(node->right, maxi);
    maxi = max(maxi, node->val + left + right);
    return node->val + max(left, right);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return -1;
    long long maxi = -1;
    f(root, maxi);
    return maxi;
}
