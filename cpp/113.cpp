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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
       if(!root)return paths;
       vector<int> path;
       f(root,sum,0,path);
       return paths; 
    }

    void f(TreeNode *root,int sum,int acc,vector<int> path){
    	if(!root->left&&!root->right){
    		if(acc+root->val==sum){
    			path.push_back(root->val);
    			paths.push_back(path);
    		}
    		return ;
    	}
    	path.push_back(root->val);
    	if(root->left)f(root->left,sum,acc+root->val,path);
    	if(root->right)f(root->right,sum,acc+root->val,path);
    }
private:
	vector<vector<int>> paths;
};