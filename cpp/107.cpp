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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if(!root)return res;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()){
        	auto cur = q.front();q.pop();
        	int d = cur.second;
        	auto curnode=cur.first;
        	if(res.size()<=d)res.emplace_back();
        	res.back().push_back(curnode->val);
        	if(curnode->left)q.push(make_pair(curnode->left,d+1));
        	if(curnode->right)q.push(make_pair(curnode->right,d+1));
        }
        reverse(res.begin(),res.end());
        return res;
    }
};