/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
class PriorityQueue {
  constructor() {
    this._pq = [{key:-1, val:-1}]
    this._n = 0
  }
  empty() {
    return this._n === 0
  }
  _cmp(i, j) {
    return this._pq[i].key > this._pq[j].key
  }
  _exch(i, j) {
    [this._pq[i], this._pq[j]] = [this._pq[j], this._pq[i]]
  }
  _swim(k) {
    while (k > 1 && this._cmp(k>>1, k)) {
      this._exch(k>>1, k)
      k >>= 1
    }
  }
  _sink(k) {
    while ((k << 1) <= this._n) {
      let j = k << 1
      if (j < this._n && this._cmp(j, j+1)) j++
      if (!this._cmp(k, j)) break
      this._exch(k, j)
      k = j
    }
  }
  insert(v, idx) {
    this._pq[++this._n] = {key: v, val: idx}
    this._swim(this._n)
  }
  delMin() {
    let ret = this._pq[1]
    this._exch(1, this._n--)
    this._sink(1)
    return ret
  }
}

/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
  if (lists.length == 0) return lists
  let ans = new ListNode(0)
  let pq = new PriorityQueue(), p = ans, q = Array(lists.length) 
  lists.forEach((v, i) =>  {
    if(v != null) {
      pq.insert(v.val, i)
      q[i] = v
    }
  })
  while (q.some((v) => v != null)) {
    let min = pq.delMin() 
    p.next = q[min.val]
    p = p.next 
    q[min.val] = q[min.val].next
    if(q[min.val]) pq.insert(q[min.val].val, min.val)
  }
  return ans.next
};