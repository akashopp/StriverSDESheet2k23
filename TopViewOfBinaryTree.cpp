#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int>ans;
    if(root == NULL) return ans;
    map<int, int>mpp; 
    queue<pair<int, TreeNode<int>*>>q; 
    q.push({0, root});
    while(!q.empty()){
        TreeNode<int>* node = q.front().second;
        int level = q.front().first; 
        q.pop();
        if(mpp.find(level) == mpp.end()){
            mpp[level] = node->val;
        }
        if(node->left != NULL) q.push({level - 1, node->left}); 
        if(node->right != NULL) q.push({level + 1, node->right}); 
    }
    for(auto &it: mpp) ans.push_back(it.second);
    return ans;
}
