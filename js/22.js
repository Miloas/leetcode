/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function (n) {
	let ret = [];
	(function aux(acc, l, r) {
		if(l==n&&r==n) ret.push(acc)
		if(l>r) aux(acc+')',l,r+1)
		if(l!=n) aux(acc+'(',l+1,r)
	})('',0,0)

	return ret
};