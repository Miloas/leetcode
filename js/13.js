/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
  let r2i = {
      I: 1,
      V: 5,
      X: 10,
      L: 50,
      C: 100,
      D: 500,
      M: 1000
    },
    ret = 0,
    last = 'I'
  for (let i = s.length - 1; i >= 0; --i) {
    if (r2i[s[i]] < r2i[last]) ret -= r2i[s[i]]
    else ret += r2i[s[i]], last = s[i]
  }
  return ret
};