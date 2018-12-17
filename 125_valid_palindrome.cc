#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    for (int left = 0, right = s.size(); left < right; ++left, --right) {
      while (isalnum(s[left]) == false && left < right) ++left;
      while (isalnum(s[right]) == false && left < right) --right;
      if (toupper(s[left]) != toupper(s[right])) return false;
    }
    return true;
  }
};


int main() {
  Solution sol = Solution();
  string s = "A man, a plan, a canal: Panama";
  cout << "Is \"" << s << "\" a valid palindrome? " << sol.isPalindrome(s) << endl;
  return 0;
}
