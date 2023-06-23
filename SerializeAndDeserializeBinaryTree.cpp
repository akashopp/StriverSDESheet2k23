#include<bits/stdc++.h>
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

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    string s;
    if(root == NULL) return s;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        if(node == NULL) s += "#,";
        else{
            s += to_string(node->data) + ",";
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    if(serialized.empty()) return NULL;
    stringstream s(serialized);
    string str;
    getline(s, str, ',');
    queue<TreeNode<int>*>q;
    TreeNode<int>* root = new TreeNode<int>(stoi(str));
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        getline(s, str, ',');
        if(str == "#") node->left = NULL;
        else{
            TreeNode<int>* temp = new TreeNode<int>(stoi(str));
            q.push(temp);
            node->left = temp;
        }
        getline(s, str, ',');
        if(str == "#") node->right = NULL;
        else{
            TreeNode<int>* temp = new TreeNode<int>(stoi(str));
            q.push(temp);
            node->right = temp;
        }
    }
    return root;
}
