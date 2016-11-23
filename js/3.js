/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    var m = {}
    var i = 0, j = 0, ret = 0
    while(j < s.length) {
        if(m[s[j]] === undefined || m[s[j]] < i) {
            ret = Math.max(ret, j - i + 1)
        } else {
            i = m[s[j]] + 1
        }
        m[s[j]] = j ++
    }
    return ret
};
