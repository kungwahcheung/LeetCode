#include <iostream>
#include <string>
#include <vector>

#include "util.h"

using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    dfs(n, n, "", res);
    return res;
  }
 
 private:
  void dfs(int left, int right, string str, vector<string>& res) {
    if (right < left) return;
    if (left == 0 && right == 0) {
      res.push_back(str);
      return;
    }
    if (left > 0) dfs(left-1, right, str+"(", res);
    if (right > 0) dfs(left, right-1, str+")", res);
  }
};


int main() {
  Solution sol = Solution();
  int n;
  cout << "input n: ";
  cin >> n;
  print_vector(sol.generateParenthesis(n));
  cout << endl;
  return 0;
}
