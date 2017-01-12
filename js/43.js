/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function(num1, num2) {
	let array_of_string = (p) => {
		return Array.from(p).map((x)=>+x).reverse()
	}
	let ok = (a, i) => {
		return i < a.length
	}
	let add = function(n1, n2) {
		n1 = n1.reverse(), n2 = n2.reverse()
		let ret = [], g = 0
		for(let i = 0; i < Math.max(n1.length, n2.length); ++i) {
			let t = (ok(n1,i)?n1[i]:0) + (ok(n2,i)?n2[i]:0) + g 
			g = t / 10 | 0
			t %= 10 
			ret.unshift(t)
		}
		if(g!=0)ret.unshift(g)
		return ret
	}
	let a = array_of_string(num1), b = array_of_string(num2), c = []
	for(let i = 0; i < a.length; ++i) {
		let t = [], g = 0
		for(let j = 0; j < b.length; ++j) {
			let n = a[i] * b[j] + g 
			g = n / 10 | 0 
			n %= 10
			t.unshift(n)
		}
		if(g!=0)t.unshift(g)
		for(let k = 0; k < i; ++k) t.push(0)
		c = add(t, c)
	}
  let i = 0
  for(; i < c.length; ++i) {
    if(c[i] !== 0) break
  }
  c.splice(0, i)
	return c.length>0?c.map((x)=>x+'').join(''):"0"
};
