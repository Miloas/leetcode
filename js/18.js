/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function (nums, target) {
	let ret = [], n = nums.length;
	nums.sort((a, b) => a - b)
	for (let i = 0; i < n - 3; ++i) {
		if (i && nums[i] == nums[i - 1]) continue
		for (let j = i + 1; j < n - 2; ++j) {
			if (j > i + 1 && nums[j] == nums[j - 1]) continue
			let sum = target - nums[i] - nums[j]
			let l = j + 1, r = n - 1
			while (l < r) {
				if (nums[l] + nums[r] == sum) {
					ret.push([nums[i], nums[j], nums[l], nums[r]])
					l++,r--
					while (l < r && nums[l] == nums[l - 1]) l++
					while (l < r && nums[r] == nums[r + 1]) r--
				} else {
					if (nums[l] + nums[r] > sum) r--
					else l++
				}
			}
		}
	}
	return ret
};

