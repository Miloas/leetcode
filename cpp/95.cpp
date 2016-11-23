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
    vector<TreeNode *> generateTrees(int n) {
    	return f(1,n); 
    }
	vector<TreeNode *> f(int a,int b){
		vector<TreeNode*> res;
		if(a==b)res.push_back(new TreeNode(a));
		else if(a>b)res.push_back(NULL);
		else{
			for(int i=a;i<=b;++i){
				vector<TreeNode*> l = f(a,i-1),
								  r = f(i+1,b);
				for(int j=0;j<l.size();++j)
					for(int k=0;k<r.size();++k){
						TreeNode *m = new TreeNode(i);
						m->left=l[j];
						m->right=r[k];
						res.push_back(m);
					}
			}
		}
		return res;
	}	
};