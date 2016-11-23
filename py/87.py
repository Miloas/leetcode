def isScramble(self, s1, s2):
    if (s1, s2) in self.cache:
        return self.cache[(s1, s2)]

    if len(s1) == 1:
        self.cache[(s1,s2)] = (s1 == s2)
        return self.cache[(s1,s2)]

    length = len(s2)
    for i in range(1, length): 
        if (self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:])) \
            or (self.isScramble(s1[length-i:], s2[:i]) and self.isScramble(s1[:length-i], s2[i:])):
            self.cache[(s1,s2)] = True
            return True
    self.cache[(s1,s2)] = False
    return False