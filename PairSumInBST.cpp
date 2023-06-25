#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void f(BinaryTreeNode<int>* node, vector<int>& vec){
    if(!node) return;
    f(node->left, vec);
    vec.push_back(node->data);
    f(node->right, vec);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    if(!root) return NULL;
    vector<int>inorder;
    f(root, inorder);
    int i = 0, j = inorder.size() - 1;
    while(i < j){
        if(inorder[i] + inorder[j] == k) return 1;
        else if(inorder[i] + inorder[j] < k) i++;
        else j--;
    }
    return 0;
}
