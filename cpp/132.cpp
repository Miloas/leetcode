class Solution {
public:
  int minCut(string s) {
    if (s.empty()) return 0;
    int n = s.size();
    vector<vector<bool>> f(n, vector<bool>(n));
    vector<int> g(n+1);
    g[n] = 0;
    for(int i=n-1;i>=0;--i) {
      f[i][i] = true;
      if (i+1 < n)
        f[i][i+1] = s[i] == s[i+1];
     for(int j=i+2;j<n;++j) 
        if (f[i+1][j-1] && s[i] == s[j])
          f[i][j] = true;
      g[i] = n;
      for(int j=i;j<n;++j)
        if (f[i][j])
          g[i] = min(g[i], g[j+1]+1);
    }
    return g[0]-1;
  }
};

