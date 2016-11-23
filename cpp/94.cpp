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
    vector<int> inorderTraversal(TreeNode *root) {
    	vector<int> res;
    	stack<TreeNode*> st;
    	auto p = root;
    	while(1){
    		while(p){
    			st.push(p);
    			p=p->left;
    		}
    		if(st.empty())break;
    		p=st.top();
    		res.push_back(p->val);
    		st.pop();
    		p=p->right;
    	}
    	return res;
    }
};