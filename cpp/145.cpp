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
    vector<int> postorderTraversal(TreeNode *root) {
    	stack<TreeNode*> st;
    	vector<int> res;
    	if(!root)return res;
    	st.push(root);
    	while(!st.empty()){
    		auto cur = st.top();st.pop();
    		if(cur->left)st.push(cur->left);
    		if(cur->right)st.push(cur->right);
    		res.push_back(cur->val);
    	}
    	reverse(res.begin(),res.end());
    	return res;
    }
};