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
    bool isSymmetric(TreeNode *root) {
    	return f(root,root);
    }
    bool f(TreeNode *l,TreeNode *r){
    	if(!l&&!r)return true;
    	if(!l||!r)return false;
    	return l->val==r->val&&f(l->left,r->right)&&f(l->right,r->left);
    }

};