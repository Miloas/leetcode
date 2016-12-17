/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function (nums, target) {
  let min = 0x7fffffff, ret = target;
  nums.sort((a, b) => a - b)
  for(let idx = 0;idx<nums.length;++idx) {
      let i = idx + 1, j = nums.length - 1, x = nums[idx]
      while (i < j) {
        let t = nums[i] + nums[j] + x
        if (t == target) return t
        else if (t > target) {
          j--
          if (t - target < min) {
            min = t - target
            ret = t
          }
        } else {
          i++
          if (target - t < min) {
            min = target - t
            ret = t
          }
        }
      }
    }
  return ret
};