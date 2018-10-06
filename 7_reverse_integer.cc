#include <iostream>
#include <climits>

using std::cin;
using std::cout;
using std::endl;

class Solution {
 public:
  int reverse(int x) {
    long long y = 0;
    bool negative = x < 0 ? true : false;
    if (negative) x = -x;
    while (x) {
      y = 10 * y + x % 10;
      x = x / 10;
    }
    y = negative ? -y : y;
    return (y < INT_MIN || y > INT_MAX) ? 0 : y;
  }
};


int main() {
  Solution sol = Solution();
  int x;
  cout << "input an integer: ";
  cin >> x;
  cout << "reverse of " << x << " is " << sol.reverse(x) << endl;
  return 0;
}
