/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var c = 0
    var ret = new ListNode(-1), pos = ret
    while(l1||l2||c) {
        var v = c
        if(l1)v+=l1.val,l1=l1.next
        if(l2)v+=l2.val,l2=l2.next
        if(v>=10){
            v-=10
            c=1
        }else c=0
        pos.next = new ListNode(v)
        pos = pos.next
    }
    return ret.next
};
