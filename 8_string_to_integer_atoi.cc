#include <iostream>
#include <string>
#include <climits>  // INT_MIN, INT_MAX
#include <cstdlib>  // atoi

using namespace std;

class Solution {
 public:
  int myAtoi(string str) {
    long long res = 0;
    int i = 0;
    
    // handle leading whitespace
    while (i < str.length() && str[i] == ' ') ++i;
    
    // handle plus/minus sign
    int sign = 1;
    if (i < str.length() && str[i] == '-') {
      sign = -1;
      ++i;
    } else if (i < str.length() && str[i] == '+') {
      sign = 1;  // we don't need this, just make it more clear
      ++i;
    }

    // handle main part
    while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
      res = 10 * res + (str[i] - '0');
      if (sign * res < INT_MIN) return INT_MIN;
      if (sign * res > INT_MAX) return INT_MAX;
      ++i;
    }
    return sign * res;
  }
};


int main() {
  Solution sol = Solution();
  string str;
  cout << "input a string: ";
  cin >> str;
  cout << "atoi(" << str << ") = " << sol.myAtoi(str) << endl;
  return 0;
}
