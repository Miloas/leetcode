class Solution(object):

    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        ret = 0
        op = 1
        ct = 0
        for ch in str.strip():
            ct += 1
            if (ch == '-' or ch == '+') and ct == 1:
                op = -1 if ch == '-' else 1
            elif ch >= '0' and ch <= '9':
                ret = ret * 10 + int(ch)
                if ret * op >= 0x7fffffff:
                    return 0x7fffffff
                if ret * op <= -0x80000000:
                    return -0x80000000
            else:
                break
        return ret * op
