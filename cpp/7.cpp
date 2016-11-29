class Solution {
 public:
  int reverse(int x) {
    int ret = 0, op = 1;
    if (x < 0) op = -1, x = -x;
    while (x) {
      int t = ret;
      ret = ret * 10 + x % 10;
      if (t != (ret - x % 10) / 10) return 0;
      x /= 10;
    }
    return ret * op;
  }
};
