class Solution {
 public:
  string intToRoman(int num) {
    const int BASE[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string ROMAN[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                            "XL", "X",  "IX", "V",  "IV", "I"};
    string ans = "";
    for (int i = 0; num; ++i) {
      int t = num / BASE[i];
      while (t--) ans += ROMAN[i];
      num %= ROMAN[i];
    }
    return ans;
  }
};