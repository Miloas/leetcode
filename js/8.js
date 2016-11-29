/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function (str) {
    let s = str.trim(),
        ret = 0,
        op = 1
    for (let i = 0; i < s.length;) {
        if (s[i] === '-' || s[i] === '+') {
            op = (s[i++] === '-') ? -1 : 1
        }
        while (s[i] >= '0' && s[i] <= '9') {
            ret = ret * 10 + (+s[i++])
            if (ret * op >= 0x7fffffff) return 0x7fffffff
            if (ret * op < -0x80000000) return -0x80000000
        }
        return ret * op
    }
    return ret
};