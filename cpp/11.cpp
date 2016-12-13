class Solution {
 public:
  inline int getArea(int i, int j, vector<int>& h) {
    return (j - i) * min(h[i], h[j]);
  }
  int maxArea(vector<int>& h) {
    int n = h.size();
    int i = 0, j = n - 1, ret = 0;
    while (i < j) {
      int t = getArea(i, j, h);
      ret = max(ret, t);
      if (h[i] < h[j]) i++;
      else j--;
    }
    return ret;
  }
};