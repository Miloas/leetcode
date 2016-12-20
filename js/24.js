/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
  let ans = new ListNode(0)
  ans.next = head
  function swap(pre, cur, next) {
    cur.next = next.next 
    next.next = cur 
    pre.next = next
  }
  let p = ans
  while(p && p.next && p.next.next) {
    swap(p, p.next, p.next.next) 
    p = p.next.next 
  } 
  return ans.next
};