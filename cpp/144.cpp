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
    vector<int> preorderTraversal(TreeNode *root) {
    	stack<TreeNode*> st;
    	vector<int> res;
    	if(!root)return res;
    	st.push(root);
    	while(!st.empty()){
    		auto cur = st.top();st.pop();
    		res.push_back(cur->val);
    		if(cur->right)st.push(cur->right);
    		if(cur->left)st.push(cur->left);
    	}
    	return res;
    }
};