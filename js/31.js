/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
	if(nums.length <= 1) return 
	function rev(a, i, j) {
		while(i<j) {
			[a[i], a[j]] = [a[j], a[i]]
			i++,j--
		}
	}
	for(let i = nums.length - 1; i >=0; i--) {
		if(nums[i]<nums[i+1]){
			let j = nums.length
			while(nums[i]>=nums[--j]);
			[nums[i],nums[j]] = [nums[j],nums[i]]
			rev(nums, i+1, nums.length-1)
			return
		}
	}
	rev(nums, 0, nums.length-1)
};
