/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
  let l = 0, r = height.length - 1, maxs = 0, ret = 0 
  while (l < r) {
    let lower = height[height[l] < height[r] ? l++ : r--]
    maxs = Math.max(maxs, lower)
    ret += maxs - lower
  }
  return ret
};