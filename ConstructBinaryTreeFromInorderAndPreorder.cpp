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
TreeNode<int>* f(int preStart, int preEnd, vector<int>& preorder, int inStart, int inEnd, vector<int>& inorder, unordered_map<int, int>& mpp){
    if(preStart > preEnd || inStart > inEnd) return NULL;
    TreeNode<int>* root = new TreeNode<int>(preorder[preStart]);
    int ind = mpp[preorder[preStart]];
    int cnt = ind - inStart;
    root->left = f(preStart + 1, preStart + cnt, preorder, inStart, ind - 1, inorder, mpp);
    root->right = f(preStart + cnt + 1, preEnd, preorder, ind + 1, inEnd, inorder, mpp); 
    return root; 
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    unordered_map<int, int>mpp;
    for(int i = 0; i < inorder.size(); i++) mpp[inorder[i]] = i;
    return f(0, preorder.size()-1, preorder, 0, inorder.size()-1, inorder, mpp);
}
