/**
 * @param {number} dd
 * @param {number} ds
 * @return {number}
 */
var divide = function(dividend, divisor) {
	if(divisor==0) return 0x7fffffff
	let neg = -1, res = 0>>>0, dd = dividend, ds = divisor
	if(dd<0&&ds<0||dd>0&&ds>0) neg = 1
	if(dd<0)dd = (-dd)>>>0
	if(ds<0)ds = (-ds)>>>0
	for(let i = 31; i >= 0; i--) {
		if((dd>>>i)>=ds) {
			res += (1 << i)>>>0
			dd -= (ds << i)
		}
	}
	if(neg==1){
		if(res > 0x7fffffff) return 0x7fffffff
		else return res
	} else {
		if(res > ((1<<31)+1)>>>0) return 0x7fffffff
		return -res
	}
};
