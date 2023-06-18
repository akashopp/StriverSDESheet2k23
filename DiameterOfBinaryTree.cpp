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
int f(TreeNode<int>* node, int& maxi){
    if(node == NULL) return 0; 
    int leftH = f(node->left, maxi); 
    int rightH = f(node->right, maxi); 
    maxi = max(maxi, leftH + rightH); 
    return 1 + max(leftH, rightH); 
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int maxi = 0; 
    int ans = f(root, maxi);
    return maxi; 
}
