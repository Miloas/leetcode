/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
	let l = 0, r = nums.length - 1, ret = []
	while(l < r){
		let m = (l + r) >> 1 
		if(nums[m] >= target) r = m 
		else l = m + 1 
	}
	if(nums[l] != target) return [-1, -1]
	ret.push(l)
	l = 0, r = nums.length
	while(r - l > 1) {
		let m = (l + r) >> 1
		if(nums[m] <= target) l = m
		else r = m
	}
	ret.push(l)
	return ret
};