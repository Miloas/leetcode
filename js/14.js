/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  if (strs.length === 0) return ""
  let n = Math.min(...strs.map((item) => item.length))
  function aux(i) {
    if (i >= n) return ""
    if (strs.every((item) => item[i] === strs[0][i])) return strs[0][i] + aux(i + 1)
    else return ""
  }
  return aux(0)
};