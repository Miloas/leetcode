#define maxn 2001
int n, k;
int sa[maxn], lcp[maxn], rk[maxn], tmp[maxn], d[maxn][12];

bool cmp_sa(int i, int j) {
  if (rk[i] != rk[j])
    return rk[i] < rk[j];
  else {
    int ri = i + k <= n ? rk[i + k] : -1;
    int rj = j + k <= n ? rk[j + k] : -1;
    return ri < rj;
  }
}
class Solution {
 public:
  void construct_sa(string S, int *sa) {
    n = S.length();
    for (int i = 0; i <= n; i++) {
      sa[i] = i;
      rk[i] = i < n ? S[i] : -1;
    }
    for (k = 1; k <= n; k <<= 1) {
      sort(sa, sa + n + 1, cmp_sa);
      tmp[sa[0]] = 0;
      for (int i = 1; i <= n; i++) {
        tmp[sa[i]] = tmp[sa[i - 1]] + (cmp_sa(sa[i - 1], sa[i]) ? 1 : 0);
      }
      for (int i = 0; i <= n; i++) {
        rk[i] = tmp[i];
      }
    }
  }

  void construct_lcp(string S, int *sa, int *lcp) {
    n = S.length();
    for (int i = 0; i <= n; i++) rk[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; i++) {
      int j = sa[rk[i] - 1];
      for (h ? h-- : 0; i + h < n && j + h < n && S[i + h] == S[j + h]; h++)
        ;
      lcp[rk[i] - 1] = h;
    }
  }

  void construct_rmq(int *lcp, int sz) {
    for (int i = 0; i <= sz; i++) d[i][0] = lcp[i];
    for (int j = 1; (1 << j) <= sz; j++) {
      for (int i = 0; (i + (1 << j) - 1) <= sz; i++) {
        d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  int rmq_query(int l, int r) {
    if (l > r) swap(l, r);
    r -= 1;
    int k = 0;
    int len = r - l + 1;
    while ((1 << (k + 1)) < len) k++;
    return min(d[l][k], d[r - (1 << k) + 1][k]);
  }

  string longestPalindrome(string S) {
    int m = S.length();
    string T = S;
    reverse(T.begin(), T.end());
    S += '#' + T;
    construct_sa(S, sa);
    construct_lcp(S, sa, lcp);
    construct_rmq(lcp, S.length() + 1);
    int ans = 0;
    int ansid;
    int anstype;
    for (int i = 0; i < m; i++) {
      int j = 2 * m - i;
      int l = rmq_query(rk[i], rk[j]);
      if (2 * l - 1 > ans) {
        ans = 2 * l - 1;
        ansid = i;
        anstype = 0;
      }
    }
    for (int i = 1; i < m; i++) {
      int j = 2 * m - i + 1;
      int l = rmq_query(rk[i], rk[j]);
      if (2 * l > ans) {
        ansid = i;
        anstype = 1;
        ans = 2 * l;
      }
    }
    return S.substr(ansid - (anstype ? ans / 2 : (ans - 1) / 2), ans);
  }
};