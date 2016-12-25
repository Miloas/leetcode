/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
  let l = 0, r = nums.length - 1
  while(l < r) {
    let m = (l + r) >> 1 
    if(nums[m] == target) return m 
    if(nums[l] <= nums[m]) {
      if(target >= nums[l] && target < nums[m]) {
        r = m - 1
      } else {
        l = m + 1
      }
    } else {
      if(target > nums[m] && target <= nums[r]) {
        l = m + 1
      } else {
        r = m - 1
      }
    }
  }
  return nums[l] == target ? l : -1
};