/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (h) {
    let getArea = (i, j) => (j - i) * Math.min(h[i], h[j])
    let i = 0, j = h.length - 1, ret = 0
    while (i < j) {
        ret = Math.max(ret, getArea(i, j))
        if (h[i] < h[j]) i++
        else j--
    }
    return ret
};