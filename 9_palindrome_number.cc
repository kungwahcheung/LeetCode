#include <iostream>
#include <string>
#include <cstdlib>  // atoi

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    string nums = to_string(x);
    for (int left = 0, right = nums.size() - 1; left < right; /**/) {
      if (nums[left] != nums[right]) return false;
      ++left;
      --right;
    }
    return true;
  }
};


int main() {
  Solution sol = Solution();
  string s;
  cout << "input an integer: ";
  cin >> s;
  int x = atoi(s.c_str());
  cout << "isPalindrome = " << sol.isPalindrome(x) << endl;
  return 0;
}
