/**
 * 使用迭代解法, 与89_gray_code.cc有相似之处
 * 程序正确性的证明需要使用数学归纳法:
 * 当k = 1时, subsets_(1) = {{}, {nums[0]}}
 * 假设当i = k的循环结束后, nums[0,1,2,...,k]的subsets已经找到, 称之为subsets_(k);
 * 当i = k + 1时, 如果我们在保留subsets_(k)的同时, 对于subsets_(k)中的每个元素,
 * 添加nums[k+1], 那么新的集合subsets_(k+1)同时包含了nums[0,1,2,...,k,k+1]这些元素
 * 组成的包含num[k+1]的子集 & 不包含num[k+1]的子集, 这两个子集合起来
 * 就是nums[0,1,2,...,k,k+1]的子集
 */

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    res.push_back(vector<int>());  // 先加入空集
    for (int i = 0; i < nums.size(); ++i) {
      int size = res.size();
      for (int j = 0; j < size; ++j) {
        res.push_back(res[j]);
        res.back().push_back(nums[i]);
      }
    }
    return res;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> my_subsets = sol.subsets(nums);
  for (auto subset : my_subsets) {
    cout << "[";
    for (auto it : subset) cout << it << " ";
    cout << "]" << endl;
  }
  return 0;
}
