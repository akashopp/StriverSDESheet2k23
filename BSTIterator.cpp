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

class BSTiterator
{   
    stack<TreeNode<int>*>st;
public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        // write your code here
        TreeNode<int>* node = st.top();
        int ans = node->data;
        st.pop();
        if(node->right != NULL){
            node = node->right; 
            while(node != NULL) st.push(node), node = node->left; 
        }
        return ans;
    }

    bool hasNext()
    {
        // write your code here
        return !st.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
