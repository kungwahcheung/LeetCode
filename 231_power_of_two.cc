#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n-1)) == 0;
  }
};


int main() {
  Solution sol = Solution();
  int n = 0;
  cout << "input an integer: ";
  cin >> n;
  cout << n << " is power of two? ==> " << (sol.isPowerOfTwo(n) ? "true" : "false") << endl;
  return 0;
}
