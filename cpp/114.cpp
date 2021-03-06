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
    void flatten(TreeNode *root) {
 		while(root){
 			if(root->left){
 				TreeNode *x = root->left;
 				while(x->right)x=x->right;
 				x->right=root->right;
 				root->right=root->left;
 				root->left=NULL;
 			}
 			root=root->right;
 		}       
    }
};