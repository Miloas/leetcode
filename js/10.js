/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function (s, p) {
  let dp = Array(s.length + 1).fill().map(() => Array(p.length + 1).fill(-1));

  function f(i, j) {
    if (dp[i][j] != -1) return dp[i][j]
    if (j == p.length) return dp[i][j] = i == s.length
    if (j + 1 == p.length || p[j + 1] != '*')
      if (i < s.length && (s[i] == p[j] || p[j] == '.')) return dp[i][j] = f(i + 1, j + 1)
    if (j + 1 < p.length && p[j + 1] == '*') {
      dp[i][j] = f(i, j + 2)
      if (i < s.length && (s[i] == p[j] || p[j] == '.')) {
        dp[i][j] = dp[i][j] || f(i + 1, j)
      }
      return dp[i][j]
    }
    return dp[i][j] = 0
  }
  return f(0, 0) == 1
};