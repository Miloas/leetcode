class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        ret = int(str(x)[::-1]) if x>=0 else -int(str(x)[1:][::-1])
        if ret > 0x7fffffff or ret <= -0x80000000:
            return 0
        return int(ret)