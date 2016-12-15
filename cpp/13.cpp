class Solution {
 public:
  int romanToInt(string s) {
    int r2i[256], ret = 0, last = 'I';
    r2i['I'] = 1;
    r2i['V'] = 5;
    r2i['X'] = 10;
    r2i['L'] = 50;
    r2i['C'] = 100;
    r2i['D'] = 500;
    r2i['M'] = 1000;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (r2i[s[i]] < r2i[last])
        ret -= r2i[s[i]];
      else {
        ret += r2i[s[i]];
        last = s[i];
      }
    }
    return ret;
  }
};