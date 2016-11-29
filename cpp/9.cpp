class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    string xs = to_string(x), ts = xs;
    reverse(xs.begin(), xs.end());
    return xs == ts;
  }
};