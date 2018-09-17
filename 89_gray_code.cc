/**
 * 查看geeksforgeeks关于gray code的讲解:
 * https://www.geeksforgeeks.org/given-a-number-n-generate-bit-patterns-from-0-to-2n-1-so-that-successive-patterns-differ-by-one-bit/
 * https://www.geeksforgeeks.org/gray-to-binary-and-binary-to-gray-conversion/
 */

#include <vector>
#include <iostream>
#include <cmath>

using std::vector;
using std::cout;
using std::endl;

class Solution {
 public:
  vector<int> grayCode(int n) {
    if (n == 0) return {0};
    vector<int> res{0, 1};
    for (int i = 1; i < n; ++i) {
      int size = res.size();
      for (int j = size - 1; j >= 0; --j) {
        res.push_back((1 << i) | res[j]);
      }
    }
    return res;
  }

  vector<int> grayCode_trick(int n) {
    vector<int> result = vector<int> (1 << n, 0);
    for (int i = 0; i < 1 << n; ++i) {
      result[i] = i ^ i >> 1;
    }
    return result;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> res = sol.grayCode(3);
  for (auto it : res)
    cout << it << '\t';
  cout << endl;
  return 0;
}
