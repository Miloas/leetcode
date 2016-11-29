/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function (s, numRows) {
    if (numRows === 1) return s
    let ret = ''
    for (let i = 0; i < numRows; ++i) {
        for (let j = i; j < s.length; j += 2 * numRows - 2) {
            ret += s[j]
            if (i > 0 && i < numRows - 1 && j + (numRows - i - 1) * 2 < s.length) {
                ret += s[j + (numRows - i - 1) * 2]
            }
        }
    }
    return ret
};