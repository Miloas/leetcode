/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
	let ret = []
  candidates.sort((a,b) => a-b)
	let dfs = (d, v, xs) => {
		if(v == 0) {
			let ys = Object.assign([], xs)
			ret.push(ys)
			return 
		}
		for(let i = d; i < candidates.length; ++i) {
			if(v < candidates[i]) return 
			xs.push(candidates[i])
			dfs(i, v - candidates[i], xs)
			xs.pop()
		}
	}
	dfs(0, target, [])
	return ret
};
