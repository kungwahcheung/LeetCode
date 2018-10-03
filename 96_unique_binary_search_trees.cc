#include <vector>
#include <iostream>

using std::vector;

class Solution {
 public:
  int numTrees(int n) {
    vector<int> count(n + 1, 0);
    count[0] = count[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {  // 左子树有j个Node
        count[i] += count[j] * count[i-j-1];
      }
    }
    return count[n];
  }
};


int main () {
  Solution sol = Solution();
  int count = sol.numTrees(5);
  std::cout << count << std::endl;
  return 0;
}
