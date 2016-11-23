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
    bool isBalanced(TreeNode *root) {
       bool res=true;
       dfs(root,res);
       return res; 
    }
    int dfs(TreeNode* root,bool &res){
    	if(!root || !res)return 0;
    	int l=dfs(root->left);
    	int r=dfs(root->right);
    	if(abs(l-r)>1)res=false;
    	return max(l,r)+1;
    }
};