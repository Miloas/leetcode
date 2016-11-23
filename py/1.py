class Solution(object):
        def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        m = {}
        for i, v in enumerate(nums):
            if target - v in m:
                return [m[target - v], i]
            m[v] = i
        
