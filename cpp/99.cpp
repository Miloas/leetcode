/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
       x=y=NULL; 
       pre=new TreeNode(INT_MIN);
       inorder(root);
       swap(x->val,y->val);
    }
    void inorder(TreeNode *root){
    	if(!root)return ;
    	inorder(root->left);
    	if(!x&&pre->val>=root->val)x=pre;
    	if(x&&pre->val>=root->val)y=root;
    	pre=root;
    	inorder(root->right);
    }
private:
	TreeNode *x,*y;
	TreeNode *pre;
};