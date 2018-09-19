/**
 * 有点斐波那契数列求和的感觉, 不过多了一些限制:
 * '0'不能单独解码, 两位的码值不能超过26, 且十位上的数字不能是'0'
 * 首先想到用递归解法, 但把分类写得比较复杂了, 不好处理,
 * 容易忽略一些特殊情况, 而且递归的解法提交的时候也因为超时而没有通过...
 * 因为递归解法的时间复杂度特别高, 为O(2^n), 这是由于多次重复计算了中间值
 * 显然, 容易想到考虑DP解法.
 * 由于没有找到统一处理各种情况的方法, 自己写的DP解法的代码简直没法看, 下面是别人的DP的简洁的代码.
 */

#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Solution {
 public:
  int numDecodings_v1(string s) {
    if (s.empty() || s[0] == '0') return 0;
    vector<int> dp(s.size()+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= s.size(); ++i) {
      // s[0,1,...,i-1]是当前考虑的code
      dp[i] = (s[i-1] == '0') ? 0 : dp[i-1];  // 若是s[i-1]为'0', s不能在s[i-2]与s[i-1]之间切分, 否则, 先继承s[0,...,i-2]的计数
                                              // 还需要看看考虑s[i-3]与s[i-2]之间能不能切分, 如果能切分, 则同时继承s[0,...,i-3]的计数
      if (i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')))
        dp[i] += dp[i-2];
    }
    return dp.back();
  }

  /* 上面处理dp数组和字符串s的下标的方式感觉会有点别扭, 既然这个dp方法只是使用了前面的两个值, 可以省去创建dp数组的空间 */
  int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    int a = 1;  // a保存s[i-2]的num of decode ways
    int b = 1;  // b保存s[i-1]的num of decode ways
    int c = 1;  // c保存s[i]的num of decode ways
    for (int i = 0; i < s.size(); ++i) {
      c = (s[i] == '0') ? 0 : b;
      if (i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))) {
        c += a;
      }
      a = b;
      b = c;
    }
    return c;
  }
};

int main() {
  Solution sol = Solution();
  vector<string> ss = {"226", "101", "110", "611"};
  for (auto s : ss) {
    cout << s << " -> " << sol.numDecodings(s) << endl;
  }
  return 0;
}
