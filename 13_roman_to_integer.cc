#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> map{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int res = 0;
    for (int i = 0; i < s.length(); ++i) {
      res += map[s[i]];
      if (i > 0 && map[s[i-1]] < map[s[i]])
        res -= 2 * map[s[i-1]];
    }
    return res;
  }
};


int main() {
  Solution sol = Solution();
  string roman;
  cout << "input a roman numeral: ";
  cin >> roman;
  cout << sol.romanToInt(roman) << endl;
  return 0;
}
