class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    bool f[m + 1][n + 1];
    memset(f, 0, sizeof f);
    f[0][0] = true;
    for (int i = 0; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {
        if (p[j - 1] != '*') {
          if (i && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
            f[i][j] = f[i - 1][j - 1];
        } else if (j > 1) {
          f[i][j] = f[i][j - 2];
          if (i && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
            f[i][j] = f[i][j] || f[i - 1][j];
        }
      }
    return f[m][n];
  }
};