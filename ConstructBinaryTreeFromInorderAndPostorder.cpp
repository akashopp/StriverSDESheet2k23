#include<unordered_map>
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* f(int postStart, int postEnd, int inStart, int inEnd, vector<int>& postOrder, vector<int>& inOrder, unordered_map<int, int>& mpp){
     if(postStart > postEnd || inStart > inEnd) return NULL;
     TreeNode<int>* root = new TreeNode<int>(postOrder[postEnd]); 
     int ind = mpp[root->data]; 
     int cnt = inEnd - ind; 
     // cout<<cnt<<endl;
     // return NULL;
     root->right = f(postEnd - cnt, postEnd - 1, ind + 1, inEnd, postOrder, inOrder, mpp);
     root->left = f(postStart, postEnd - cnt - 1, inStart, ind - 1, postOrder, inOrder, mpp); 
     return root; 
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     unordered_map<int, int>mpp;
     for(int i = 0; i < inOrder.size(); i++) mpp[inOrder[i]] = i; 
     return f(0, postOrder.size()-1, 0, inOrder.size()-1, postOrder, inOrder, mpp);
}
