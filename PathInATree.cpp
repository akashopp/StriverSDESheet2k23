#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/
bool f(TreeNode<int>* node, int x, vector<int>& arr){
	if(node == NULL) return 0; 
	arr.push_back(node->data); 
	if(node->data == x) return 1; 
	if(f(node->left, x, arr) || f(node->right, x, arr)) return 1; 
	arr.pop_back(); 
	return 0; 
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int>arr; 
	if(root == NULL) return arr;
	f(root, x, arr);
	return arr;
}
