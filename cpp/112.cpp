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
    bool hasPathSum(TreeNode *root, int sum) {
    	return f(root,sum,0);
    }
    bool f(TreeNode *root,int sum,int acc){
    	if(!root->left&&!root->right){
    		if(acc+root->val==sum)return true;
    		else return false;
    	}
    	if(root->left&&f(root->left,sum,acc+root->val))return true;
    	if(root->right&&f(root->right,sum,acc+root->val))return true;
    }
};