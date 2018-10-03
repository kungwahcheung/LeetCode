/**
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 *              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using std::string;
using std::unordered_map;
using std::max;
using std::cout;
using std::endl;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int max_len = 0;
    unordered_map<char, int> map;
    int start = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (map.count(s[i]) > 0 && map[s[i]] >= start)
        start = map[s[i]] + 1;
      max_len = max(max_len, i - start + 1);
      map[s[i]] = i;
    }
    return max_len;
  }
};


int main() {
  Solution sol = Solution();
  string s = "abcabcbb";
  cout << sol.lengthOfLongestSubstring(s) << endl;
}
