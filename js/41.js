/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
  let swap = (i, j) => {
    [nums[i], nums[j]] = [nums[j], nums[i]]
  }
  for(let i = 0; i < nums.length; ++i) {
    while(nums[i] > 0 && nums[nums[i]-1] != nums[i]) {
      swap(nums[i] - 1, i)
    }
  }
  for(let i = 0; i < nums.length; ++i) {
    if(nums[i] != i + 1) return i + 1
  }
  return nums.length + 1
};