/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
    let ret = x > 0 ? +(x + '').split('').reverse().join('') : -(x + '').split('').splice(1).reverse().join('')
    if (ret > 0x7fffffff || ret <= -0x80000000) return 0
    return ret
};