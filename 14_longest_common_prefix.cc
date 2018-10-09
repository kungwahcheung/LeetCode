#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    int count = 0;
    int min_len = strs[0].length();
    for (int i = 1; i < strs.size(); ++i)
      min_len = strs[i].length() < min_len ? strs[i].length() : min_len;
    for (int n = 0; n < min_len; ++n) {
      for (int i = 1; i < strs.size(); ++i) {
        if (strs[i][n] != strs[0][n])
          return strs[0].substr(0, count);
      }
      ++count;
    }
    return strs[0].substr(0, count);
  }
};


int main() {
  Solution sol = Solution();
  vector<string> strs{"flower", "flow", "flight"};
  cout << sol.longestCommonPrefix(strs) << endl;
  return 0;
}
