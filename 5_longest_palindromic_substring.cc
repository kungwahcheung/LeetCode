#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.length() == 0) return s;
    string res = s.substr(0, 1);
    int left = 0, right = 0;
    for (int i = 0; i < s.length(); ++i) {
      // 判断[...,left]和[right,...]
      left = i;
      right = i + 1;
      while (left >= 0 && right < s.length() && s[left] == s[right]) {
        --left;
        ++right;
      }
      if (right != i and right - left - 1 > res.length())
        res = s.substr(left+1, right - left - 1);
      
      // 判断[...,left], i, [right,...]
      left = i - 1;
      right = i + 1;
      while (left >= 0 && right < s.length() && s[left] == s[right]) {
        --left;
        ++right;
      }
      if (right != i and right - left - 1 > res.length())
        res = s.substr(left+1, right - left - 1);
    }
    return res;
  }
};


int main() {
  Solution sol = Solution();
  string s;
  cout << "input a string: ";
  cin >> s;
  cout << "longest palindrome is: " << sol.longestPalindrome(s) << endl;
  return 0;
}
