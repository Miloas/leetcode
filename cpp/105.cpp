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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
       return f(0,inorder.size()-1,inorder,0,preorder.size()-1,preorder); 
    }
    TreeNode *f(int ll,int rr,vector<int>&inorder,int l,int r,vector<int> &preorder){
    	if(l>r)return NULL;
    	int midval=preorder[l];
    	TreeNode *mid = new TreeNode(midval);
    	int m=find(inorder.begin(),inorder.end(),midval)-inorder.begin();
    	mid->left=f(ll,m-1,inorder,l+1,l+m-ll,preorder);
    	mid->right=f(m+1,rr,inorder,l+m-ll+1,r,preorder);
    	return mid;
    }
};