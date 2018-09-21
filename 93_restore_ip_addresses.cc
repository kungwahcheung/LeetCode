/**
 * 下面的代码思路比较直接, 但用下标来做定界点不是一个好做法, 导致了定界比较复杂凌乱.
 * 更简洁的写法参考 https://leetcode.com/problems/restore-ip-addresses/discuss/30972/WHO-CAN-BEAT-THIS-CODE
 * 但用多个for循环的做法不具备可扩展性, 这类问题可以考虑使用DFS的做法
 */

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::to_string;
using std::cout;
using std::endl;

class Solution {
 public:
  // 用多个for循环的方法看后面, 这里先看DFS的解法
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string ip;
    dfs(s, 0, 0, ip, res);
    return res;
  }
  void dfs(string& s, int start, int step, string ip, vector<string>& res) {
    if (start == s.size() && step == 4) {
      ip.pop_back();
      res.push_back(ip);
      return;
    }
    if (step >= 4 || start >= s.size()) return;
    for (int i = start; i < s.size() && i < start + 3; ++i) {
      string segment = s.substr(start, i - start + 1);
      if (stoi(segment) > 255 || (segment[0] == '0' && segment.size() > 1)) break;
      dfs(s, i + 1, step + 1, ip + segment + ".", res);
    }
  }
/*
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    if (s.size() < 4) return res;
    int a, b, c, d;
    // 切分为[0, i] / [i+1, j] / [j+1, k] / [k+1, s.size()-1]
    for (int i = 0; i < s.size() - 3 && i < 3; ++i) {
      a = stoi(s.substr(0, i+1));
      if (a  > 255) continue;
      for (int j = i + 1; (j < s.size() - 2) && (j - i <= 3); ++j) {
        b = stoi(s.substr(i + 1, j - i));
        if (b > 255) continue;
        for (int k = j + 1; (k < s.size() - 1) && (k - j <= 3); ++k) {
          if (s.size() - k - 1 > 3) continue;
          c = stoi(s.substr(j + 1, k - j));
          if (c > 255) continue;
          d = stoi(s.substr(k+1));
          if (d > 255) continue;
          string ip = to_string(a) + "." + to_string(b) + "." +to_string(c) + "." +to_string(d);
          if (ip.size() != s.size() + 3) continue;  // 避免01.00.1.0这一类某一节带有0开头的ip
          res.push_back(ip);
        }
      }
    }
    return res;
  }
*/

/*
  // 来自Discuss的简洁的写法
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string ans;
    for (int a = 1; a <= 3; ++a)
      for (int b = 1; b <= 3; ++b)
        for (int c = 1; c <= 3; ++c)
          for (int d = 1; d <= 3; ++d)
            if (a + b + c + d == s.length()) {
              int aval = stoi(s.substr(0, a));
              int bval = stoi(s.substr(a, b));
              int cval = stoi(s.substr(a + b, c));
              int dval = stoi(s.substr(a + b + c, d));
              if (aval <= 255 && bval <= 255 && cval <= 255 && dval <= 255) {
                ans = to_string(aval) + "." + to_string(bval) + "." + to_string(cval) + "." + to_string(dval);
                if (ans.length() == s.length() + 3)
                  res.push_back(ans);
              }
            }
    return res;
  }
*/
};

int main() {
  Solution sol = Solution();
  vector<string> samples = {"25525511135", "0279245587303", "010010"};
  for (auto s : samples) {
    cout << s << endl;
    vector<string> res = sol.restoreIpAddresses(s);
    for (auto it : res)
      cout << it << endl;
    cout << endl;
  }
  return 0;
}
