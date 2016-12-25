/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
	let f = Array(s.length+1).fill(0), ret = 0
	for(let i = 1; i < s.length; ++i) {
		if(s[i] == ')') {
			let j = i - f[i-1] - 1
			if(j >= 0 && s[j] == '(') {
				f[i] = f[i-1] + 2 + (j-1 >= 0 ? f[j-1] : 0)
				ret = Math.max(ret, f[i])
			}
		}
	}
	return ret
};