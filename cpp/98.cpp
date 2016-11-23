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
    bool isValidBST(TreeNode *root) {
        return  f(root,LLONG_MIN,LLONG_MAX);
    }
    bool f(TreeNode *root,long long l,long long r){
    	if(!root)return true;
    	if(root->val>l&&root->val<r)
    		return f(root->left,l,root->val)&&f(root->right,root->val,r);
    	return false;	
    }
};