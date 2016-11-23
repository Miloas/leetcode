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
    int minDepth(TreeNode *root) {
        if(!root)return 0;
        res=INT_MAX;
        dfs(root,0);
        return res;
    }
    void dfs(TreeNode *root,int d){
    	if(!root->left&&!root->right){
    		res=min(res,d+1);
    		return;
    	}
    	if(root->left)dfs(root->left,d+1);
    	if(root->right)dfs(root->right,d+1);
    }
private:
	int res;
};