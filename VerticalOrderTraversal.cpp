#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
void f(TreeNode<int>* node, int x, int y, map<pair<int, int>, vector<int>>&mpp){
    mpp[{x, y}].push_back(node->data); 
    if(node->left != NULL) f(node->left, x-1, y+1, mpp);
    if(node->right != NULL) f(node->right, x+1, y+1, mpp); 
}
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int>ans;
    map<pair<int, int>, vector<int>>mpp; 
    f(root, 0, 0, mpp);
    for(auto &it: mpp){
        for(auto &itr: it.second) ans.push_back(itr);
    }
    return ans;
}
