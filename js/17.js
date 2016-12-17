/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
		const l2n = [" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
		let ret = [], n = digits.length
		if(n==0) return ret
		function dfs(i, s) {
			if (i>=n) ret.push(s)
			else
			for(let k = 0;k<l2n[+digits[i]].length;++k){
				dfs(i+1,s+l2n[+digits[i]][k])
			}
		}
		dfs(0, '')
		return ret
};