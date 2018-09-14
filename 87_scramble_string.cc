/**
 * 这题目的说明太晦涩难懂...
 * 实际上与“通过二叉树的前序遍历序列和中序遍历序列还原二叉树”的找分割点的思路有点像
 * 两棵子树一旦确定之后, 子树的下面的结构再怎么scramble变化, 子树本身包含的字符不再更换, 只是有位置变化
 * 具体而言就是, s1和s2如果是可以通过scramble得到的string的话, 
 * 必然存在一个切分s1=s11+s12, s2=s21+s22, 
 * 使得(s11和s21是scramble的, 且s12和s22是scramble的)
 * 或者(s11和s22是scramble的, 且s12和s21是scramble的)
 * 显然, 我们得到一个递归解决这个问题的思路了。
 *     great
 *    /    \
 *   gr    eat
 *  / \    /  \
 * g   r  e   at
 *            / \
 *           a   t
 */
#include <string>
#include <iostream>
#include <algorithm>

using std::string;
using std::sort;
using std::cout;
using std::endl;

class Solution {
 public:
  bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    if (s1 == s2) return true;
    // 这里用标准库的sort是省事的办法, 使用使用字典对字符进行计数时间复杂度更低
    string scp1 = s1, scp2 = s2;
    sort(scp1.begin(), scp1.end());
    sort(scp2.begin(), scp2.end());
    if (scp1 != scp2) return false;
    for (int i = 1; i < s1.size(); ++i) {
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
        return true;
      else if (isScramble(s1.substr(0, i), s2.substr(s2.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s2.size()-i)))
        return true;
    }
    return false;
  }
};

int main() {
  Solution sol = Solution();
  string s1 = "great", s2 = "rgeat";
  cout << s1 << " and " << s2 << " is scramble? -> " << sol.isScramble(s1, s2) << endl;
  s1 = "abcde", s2 = "caebd";
  cout << s1 << " and " << s2 << " is scramble? -> " << sol.isScramble(s1, s2) << endl;
  s1 = "abc", s2 = "bca";
  cout << s1 << " and " << s2 << " is scramble? -> " << sol.isScramble(s1, s2) << endl;
  return 0;
}
