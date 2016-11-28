class Solution(object):

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        a = '.' + '.'.join(s) + '.'
        p = [0] * len(a)
        mx, x = 0, 0
        for i in xrange(len(a)):
            if i < mx and mx - i != p[x * 2 - i]:
                p[i] = min(mx - i, p[x * 2 - i])
            else:
                x, mx = i, max(i, mx)
                while mx < len(a) and x * 2 - mx >= 0 and a[mx] == a[x * 2 - mx]:
                    mx += 1
                p[i] = mx - x
        j = p.index(max(p))
        return s[(j - p[j] + 1) / 2:(j - p[j] + 1) / 2 + p[j] - 1]
