class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        return ' '.join(list(reversed(s.split())));