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
void f(TreeNode<int>* node, int level, map<int, int>& mpp){
    if(mpp.find(level) == mpp.end()) mpp[level] = node->data; 
    if(node->left != NULL) f(node->left, level + 1, mpp); 
    if(node->right != NULL) f(node->right, level + 1, mpp); 
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int>ans;
    if(root == NULL) return ans;
    map<int, int>mpp; 
    f(root, 0, mpp); 
    for(auto &it: mpp) ans.push_back(it.second);
    return ans;
}
