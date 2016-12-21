/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
		let i =0, j = 0, last = NaN
		while(j<nums.length) {
			if(nums[j]!=last) nums[i++]=nums[j], last = nums[j]
			j++
		}
		return i
};