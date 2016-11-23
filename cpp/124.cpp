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
    int maxPathSum(TreeNode *root) {
    	res = INT_MIN;
    	f(root);
    	return res;
    }
    int f(TreeNode *root){
    	if(!root)return 0;
    	int l = max(0,f(root->left)),
    		r = max(0,f(root->right));
    	res = max(res,l+r+root->val);
    	return max(l,r)+root->val;
    }
private:
	int res;
};