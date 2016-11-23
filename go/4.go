func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    n := len(nums1)
    m := len(nums2)
    var i, j int
    k := (m + n - 1) >> 1
    for k > 0 {
        p := (k - 1) >> 1
        if j + p >= m || i + p < n && nums1[i + p] < nums2[j + p] {
            i += p + 1
        } else {
            j += p + 1
        }
        k -= p + 1
    }
    var s int
    if j >= m || i < n && nums1[i] < nums2[j] {
        s = nums1[i]
        i += 1
    } else {
        s = nums2[j]
        j += 1
    }
    if (n + m) % 2 == 1 {
        return float64(s)
    } else {
        if j >= m || i < n && nums1[i] < nums2[j] {
            return float64(s + nums1[i]) * 0.5
        } else {
            return float64(s + nums2[j]) * 0.5
        }
    }
}
