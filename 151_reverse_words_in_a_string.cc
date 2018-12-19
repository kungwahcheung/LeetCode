#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * 先整体反转字符串, 再反转每一个单词.
 */

class Solution {
 public:
  void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int cur = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ') {
        if (cur != 0) s[cur++] = ' ';
        int start = cur;
        while (i < s.size() && s[i] != ' ') s[cur++] = s[i++];
        reverse(s.begin()+start, s.begin()+cur);
      }
    }
    s.erase(s.begin()+cur, s.end());
  }
};


int main() {
  Solution sol = Solution();
  string s = " the sky is blue  ";
  cout << s << endl;
  sol.reverseWords(s);
  cout << s << endl;
  return 0;
}
