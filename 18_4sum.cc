/**
 * 多次提交出错都是因为输出的结果存在重复项,
 * 如果不采取每次push_back的时候做重复判断,
 * 则需要充分考虑如何避免重复项的出现, 如下面的代码
 */

#include <algorithm>  // sort
#include <iostream>
#include <string>
#include <vector>

#include "util.h"  // print_vector_array

using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int size = nums.size();
    int left, right;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 3; ++i) {
      if (i > 0 && nums[i] == nums[i-1]) continue;
      for (int j = i + 1; j < size - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j-1]) continue;
        left = j + 1;
        right = size - 1;
        while (left < right) {
          if (nums[i] + nums[j] + nums[left] + nums[right] == target) {
            res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
            while (left < right && nums[left+1] == nums[left]) ++left;
            while (left < right && nums[right-1] == nums[right]) --right;
            ++left;
            --right;
          } else if (nums[i] + nums[j] + nums[left] + nums[right] < target) {
            ++left;
          }
          else {
            --right;
          }
        }
      }
    }
    return res;
  }
};


int main() {
  Solution sol = Solution();
  vector<int> nums{1, 0, -1, 0, -2, 2};
  int target = 0;
  vector<vector<int>> res = sol.fourSum(nums, target);
  print_vector_array(res);
  return 0;
}
