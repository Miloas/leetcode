class Solution(object):

    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        ret = ''
        for i in xrange(numRows):
            j = i
            while j < len(s):
                ret += s[j]
                if i > 0 and i < numRows - 1 and j + (numRows - i - 1) * 2 < len(s):
                    ret += s[j + (numRows - i - 1) * 2]
                j += 2 * numRows - 2
        return ret
