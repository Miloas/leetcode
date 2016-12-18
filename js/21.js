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
var mergeTwoLists = function(l1, l2) {
  let h = new ListNode(0)
  let p = h, p1 = l1, p2 = l2
  while(p2&&p1) {
    if(p1.val < p2.val) p.next = p1, p = p.next, p1 = p1.next 
    else p.next = p2, p = p.next, p2 = p2.next 
  }
  let p3 = p1 ? p1 : p2 
  while(p3) p.next = p3,p = p.next, p3 = p3.next 
  return h.next
};