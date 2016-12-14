/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function (num) {
  const base = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
  const roman = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
  let ans = ""
  for (let i = 0; num; ++i) {
    let t = num / base[i] | 0
    while (t--) ans += roman[i]
    num %= base[i]
  }
  return ans
};