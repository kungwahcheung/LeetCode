#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * 动态规划问题, 把二维数组画出来, 找出状态转移方程.
 */

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    vector<vector<bool>> dp(s1.size()+1, vector<bool> (s2.size()+1, false));
    dp[0][0] = true;
    for (int i = 1; i <= s1.size(); ++i) {
      if (dp[i-1][0] == true && s3[i-1] == s1[i-1])
        dp[i][0] = true;
    }
    for (int j = 1; j <= s2.size(); ++j) {
      if (dp[0][j-1] == true && s3[j-1] == s2[j-1])
        dp[0][j] = true;
    }
    for (int i = 1; i <= s1.size(); ++i) {
      for (int j = 1; j <= s2.size(); ++j) {
        if (dp[i][j-1] == true && s2[j-1] == s3[i+j-1])
          dp[i][j] = true;
        else if (dp[i-1][j] == true && s1[i-1] == s3[i+j-1])
          dp[i][j] = true;
      }
    }
    return dp[s1.size()][s2.size()];
  }
};


int main() {
  Solution sol = Solution();
  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
  cout << sol.isInterleave(s1, s2, s3) << endl;
  return 0;
}
