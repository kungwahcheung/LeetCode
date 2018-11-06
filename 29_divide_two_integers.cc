/**
 * 对这些变量取long long类型是为了避免某些计算结果溢出
 * 例如, 当dividend=INT_MIN时取绝对值就超过了int类型的最大值
 * 此外, tmp也可能溢出
 */

#include <iostream>
#include <string>
#include <vector>

#include <climits>
#include <cstdlib>

using namespace std;

class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (!divisor || (dividend == INT_MIN && divisor == -1))
      return INT_MAX;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    int res = 0;
    long long ldd = labs(dividend);
    long long lds = labs(divisor);
    while (ldd >= lds) {
      long long tmp = lds, multiple = 1;
      while (ldd >= (tmp << 1)) {
        tmp <<= 1;
        multiple <<= 1;
      }
      ldd -= tmp;
      res += multiple;
    }
    return sign == 1 ? res : -res;
  }
};


int main() {
  Solution sol = Solution();
  cout << INT_MIN << " : " << INT_MAX << endl;
  int dividend, divisor;
  cout << "input dividend: ";
  cin >> dividend;
  cout << "input divisor: ";
  cin >> divisor;
  cout << dividend << " / " << divisor << " = " << sol.divide(dividend, divisor) << endl;
  return 0;
}
