/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
	let h = {}, n = s.length, m = words[0].length, ret = []
	function inc(coll, key) {
	  if(!coll[key]){
		 coll[key]=1
		 return 1
	  } else {
		 coll[key]++
		 return coll[key]
	  }
	}
	words.forEach((x)=>inc(h, x)) 
	if(m * words.length > n) return []
	for(let i = 0; i < n - m * words.length + 1; i++){
	  let th = {}, f = true
	  for(let j = i; j < i + words.length * m; j+=m) {
		 let ts = s.slice(j, j+m)
		 if(!h[ts] || inc(th, ts) > h[ts]) {
			f = false
			break
		 }
	  }
	  if(f) ret.push(i)
	}
	return ret
};
