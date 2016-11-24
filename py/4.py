class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n, m, i, j = len(nums1), len(nums2), 0, 0
        mn = n + m
        k = mn - 1 >> 1
        while k > 0 :
            p = k - 1 >> 1
            if j + p >= m or (i + p < n and nums1[i + p] < nums2[j + p]): i += p + 1
            else : j += p + 1
            k -= p + 1
        s = 0
        if j >= m or (i < n and nums1[i] < nums2[j]) :
            s = nums1[i]
            i += 1
        else :
            s = nums2[j]
            j += 1
        if mn & 1 :
            return s
        else:
            if j >= m or (i < n and nums1[i] < nums2[j]) :
                return (s + nums1[i]) / 2.0
            else :
                return (s + nums2[j]) / 2.0
