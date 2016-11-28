/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
    let a = '.' + s.split('').join('.') + '.',
        p = new Array(a.length),
        x = 0,
        mx = 0
    p.fill(0)
    for (let i in a) {
        if (i < mx && p[x * 2 - i] != mx - i)
            p[i] = Math.min(mx - i, p[x * 2 - i])
        else {
            x = i
            mx = Math.max(mx, i)
            while (mx < a.length && x * 2 - mx >= 0 && a[mx] === a[x * 2 - mx]) {
                mx++
            }
            p[i] = mx - x
        }
    }
    let j = p.indexOf(Math.max.apply(null, p))
    return s.substr((j - p[j] + 1) / 2, p[j] - 1)
};