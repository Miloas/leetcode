/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
  let l = 0, r = nums.length
  while(l < r) {
    let m = (l + r) >> 1
    if(nums[m] === target) return m 
    else if(nums[m] > target) r = m 
    else l = m + 1
  }
  return r
};