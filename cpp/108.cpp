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
    TreeNode *sortedArrayToBST(vector<int> &num) {
    	return f(num,0,num.size()-1);    
    }
    TreeNode *f(vector<int> &num,int l,int r){
    	if(l>r)return NULL;
    	int m = l+(r-l)/2;
    	TreeNode *mid = new TreeNode(num[m]);
    	mid->left=f(num,l,m-1);
    	mid->right=f(num,m+1,r);
    	return mid;
    }
};