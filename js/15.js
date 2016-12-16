/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
	let ret = [];
	(nums.sort((a,b)=>a-b)).forEach((x, idx) => {
		if (idx == 0 || x != nums[idx - 1]) {
			let i = idx + 1, j = nums.length - 1
			while (i < j) {
				if (i > idx + 1 && nums[i] == nums[i - 1]) {
					i++
					continue
				}
				let t = nums[i] + nums[j] + x
				if (t > 0) j--
				else if (t < 0) i++
        else ret.push([nums[i++], x, nums[j]])
			}
		}
	})
	return ret
};

