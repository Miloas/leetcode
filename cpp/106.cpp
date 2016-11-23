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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
       return f(0,inorder.size()-1,inorder,0,postorder.size()-1,postorder); 
    }
    TreeNode *f(int ll,int rr,vector<int>&inorder,int l,int r,vector<int> &postorder){
    	if(l>r)return NULL;
    	int midval=postorder[r];
    	TreeNode *mid = new TreeNode(midval);
    	int m=find(inorder.begin(),inorder.end(),midval)-inorder.begin();
    	mid->right=f(m+1,rr,inorder,r-rr+m,r-1,postorder);
    	mid->left=f(ll,m-1,inorder,l,r-rr+m-1,postorder);
    	return mid;
    }
};