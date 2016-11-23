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
    int sumNumbers(TreeNode *root) {
   		return f(root,0);     
    }
    int f(TreeNode *u,int d){
    	if(!u)return 0;
    	if(!u->left&&!u->right) return d*10+u->val;
    	return f(u->left,d*10+u->val)+f(u->right,d*10+u->val);
    }
};