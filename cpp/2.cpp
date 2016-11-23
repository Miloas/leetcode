/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode(-1), *pos = ret;
        int c = 0;
        while(l1||l2||c){
            int v = c;
            if(l1)v+=l1->val,l1=l1->next;
            if(l2)v+=l2->val,l2=l2->next;
            c=v/10;
            v%=10;
            pos->next = new ListNode(v);
            pos=pos->next;
        }
        return ret->next;
    }
};
