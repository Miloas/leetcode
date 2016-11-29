class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string ret;
    for (int i = 0; i < numRows; i++) {
      for (int j = i; j < s.size(); j += 2 * numRows - 2) {
        ret += s[j];
        if (i > 0 && i < numRows - 1 && j + (numRows - i - 1) * 2 < s.size())
          ret += s[j + (numRows - i - 1) * 2];
      }
    }
    return ret;
  }
};