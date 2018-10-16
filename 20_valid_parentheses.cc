#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    vector<char> stack;
    for (const auto& it : s) {
      if (it == ')') {
        if (stack.empty() || stack.back() != '(') return false;
        stack.pop_back();
        continue;
      }
      if (it == ']') {
        if (stack.empty() || stack.back() != '[') return false;
        stack.pop_back();
        continue;
      }
      if (it == '}') {
        if (stack.empty() || stack.back() != '{') return false;
        stack.pop_back();
        continue;
      }
      stack.push_back(it);
    }
    return stack.empty();
  }
};


int main() {
  Solution sol = Solution();
  string s;
  cout << "input a string of brackets: ";
  cin >> s;
  cout << "valid brackets? " << (sol.isValid(s) ? "true" : "false") << endl;
  return 0;
}
