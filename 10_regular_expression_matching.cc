#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    if (p.length() == 0) return s.length() == 0 ? true : false;
    if (p[0] == '*') return false;
    if (p[0] == '.') {
      if (p.length() == 1) return s.length() == 1 ? true : false;
      if (p[1] != '*') return s.length() > 0 && isMatch(s.substr(1), p.substr(1));
      // handle ".*"
      for (int i = 0; i <= s.length(); ++i)
        if (isMatch(s.substr(i), p.substr(2))) return true;
      return false;
    } else {  // p[0] is not '.' or '*'
      if (p.length() == 1) return (s.length() == 1 && s[0] == p[0]) ? true : false;
      if (p[1] != '*') return s[0] == p[0] && isMatch(s.substr(1), p.substr(1));
      // handle "x*"
      if (isMatch(s, p.substr(2))) return true;  // match zero 'x'
      for (int i = 0; i < s.length() && s[i] == p[0]; ++i)  // match (i+1)个 'x'
        if (isMatch(s.substr(i + 1), p.substr(2))) return true;
      return false;
    }
  }
};


int main() {
  Solution sol = Solution();
  string s, p;
  cout << "input s: ";
  cin >> s;
  cout << "input p: ";
  cin >> p;
  cout << "string(" << s << ")" << " match pattern(" << p << ")? ==> " << sol.isMatch(s, p) << endl;
  return 0;
}
