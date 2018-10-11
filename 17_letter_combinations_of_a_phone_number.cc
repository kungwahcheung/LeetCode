/**
 * 采用迭代解法的经典例子之一
 * 在获取了digits.substr(i)的数字组合(记为res[i])之后, digits.substr(i+1)的数字组合为:
 * 在res[i]的每个组合后分别添加熟悉digits[i+1]对应的没一个字母
 */

#include <iostream>
#include <string>
#include <vector>

#include "util.h"  // print_vector

using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    const vector<string> digit2letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    if (digits.empty()) return res;
    res.push_back("");
    int size;  // 用于记住之前res中的元素个数
    for (int i = 0; i < digits.size(); ++i) {
      size = res.size();
      for (int j = 1; j < digit2letter[digits[i]-'0'].length(); ++j) {
        for (int k = 0; k < size; ++k) {
          res.push_back(res[k] + digit2letter[digits[i]-'0'][j]);
        }
      }
      for (int k = 0; k < size; ++k) {
        res[k] = res[k] + digit2letter[digits[i]-'0'].substr(0, 1);
      }
    }
    return res;
  }
};


int main() {
  Solution sol = Solution();
  string digits;
  cout << "input a sequence of digits: ";
  cin >> digits;
  print_vector(sol.letterCombinations(digits));
  return 0;
}
