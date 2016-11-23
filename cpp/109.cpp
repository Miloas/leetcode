/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
    	if(!head)return NULL;
    	ListNode *p,*q,*r=NULL;
    	for(p=head,q=head;q->next&&q->next->next;){
    		r=p;
    		p=p->next;
    		q=q->next->next;
    	}
    	TreeNode *mid=new TreeNode(p->val);
    	if(r){
    		r->next=NULL;
    		mid->left=sortedListToBST(head);
    	}
    	mid->right=sortedListToBST(p->next);
    	return mid;
    }
};