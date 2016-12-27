/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
  if(n == 1) return '1'
  if(n == 2) return '11'
  let res = countAndSay(n - 1), newRes = '', cnt = 1
  for(let i = 1; i < res.length; ++i) {
    if(res[i] != res[i - 1]){
      newRes = newRes + cnt + res[i-1]
      cnt = 1
    } else cnt++
    if(i == res.length - 1) {
      newRes = newRes + cnt + res[i]
    }
  }
  return newRes
};