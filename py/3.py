class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = j = ret = 0
        m = {}
        while j < len(s) :
            if m.get(s[j], -1) < i :
                ret = max(ret, j - i + 1)
            else :
                i = m[s[j]] + 1
            m[s[j]] = j
            j += 1
        return ret
