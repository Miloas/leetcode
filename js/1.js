/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var m = {}
    for(var i in nums) {
        if(m[target - nums[i]] !== undefined) {
            return [+m[target-nums[i]], +i]
        }
        m[nums[i]] = i
    }
};
