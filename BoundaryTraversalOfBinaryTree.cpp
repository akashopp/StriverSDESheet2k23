#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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
bool isLeaf(TreeNode<int>* node){
    return (node->left == NULL && node->right == NULL); 
}
void leftBound(TreeNode<int>* root, vector<int>& ans){
    TreeNode<int>* node = root->left; 
    while(node){
        if(!isLeaf(node)) ans.push_back(node->data);
        if(node->left != NULL) node = node->left; 
        else node = node->right; 
    }
}
void rightBound(TreeNode<int>* root, vector<int>& ans){
    TreeNode<int>* node = root->right; 
    vector<int>temp; 
    while(node){
        if(!isLeaf(node)) temp.push_back(node->data); 
        if(node->right != NULL) node = node->right; 
        else node = node->left; 
    }
    for(int i = temp.size()-1; i >= 0; i--) ans.push_back(temp[i]); 
}
void inorder(TreeNode<int>* node, vector<int>& ans){
    if(isLeaf(node)) ans.push_back(node->data); 
    if(node->left != NULL) inorder(node->left, ans);
    if(node->right != NULL) inorder(node->right, ans);  
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>res; 
    if(!isLeaf(root)) res.push_back(root->data); 
    leftBound(root, res); 
    inorder(root, res); 
    rightBound(root, res); 
    return res; 
}





