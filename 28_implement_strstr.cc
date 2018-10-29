#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    int times = haystack.size() - needle.size() + 1;
    for (int i = 0; i < times; ++i) {
      int j;
      for (j = 0; j < needle.size(); ++j) {
        if (needle[j] != haystack[i+j]) break;
      }
      if (j == needle.size()) return i;
    }
    return -1;
  }
};

int main() {
  Solution sol = Solution();
  string haystack, needle;
	cout << "input haystack: ";
	cin >> haystack;
  cout << "input needle: ";
  cin >> needle;
  cout << sol.strStr(haystack, needle) << endl;
  return 0;
}
