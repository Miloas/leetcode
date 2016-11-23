/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(!root) return;
 		TreeLinkNode *s=root,*e=root,*fnl=root;
 		while(s){
 			if(s->left){
 				e->next=s->left;
 				e=e->next;
 			}
 			if(s->right){
 				e->next=s->right;
 				e=e->next;
 			}
 			if(s==fnl){
 				s=s->next;
 				fnl->next=NULL;
 				fnl=e;
 			}else
 			s=s->next;
 		}
    }
};