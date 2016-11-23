/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let n = nums1.length, m = nums2.length, mn = n + m, inf = 0x7fffffff
    function kth(i, j, k) {
        let mid = k >> 1
        if(i >= n) return nums2[j + k - 1]
        if(j >= m) return nums1[i + k - 1]
        if(k == 1) return Math.min(nums1[i], nums2[j]);
        let r1 = i + mid - 1 >= n ? inf : nums1[i + mid - 1]
        let r2 = j + mid - 1 >= m ? inf : nums2[j + mid - 1]
        if(r1 < r2) return kth(i + mid, j, k - mid)
        return kth(i, j + mid, k - mid)
    }
    let mid = mn >> 1
    if(mn & 1) return kth(0, 0, mid + 1)
    else return (kth(0, 0, mid) + kth(0, 0, mid + 1)) / 2
};
