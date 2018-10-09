#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::sort;
using std::unordered_map;
using std::cout;
using std::endl;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = 0; i < size - 2; ++i) {
      if (nums[i] > 0) break;
      if (i != 0 && nums[i] == nums[i-1]) continue;
      int left = i + 1, right = nums.size() - 1, target = 0 - nums[i];
      while (left < right) {
        if (nums[left] + nums[right] < target) ++left;
        else if (nums[left] + nums[right] > target) --right;
        else {
          res.push_back({nums[i], nums[left], nums[right]});
          //while (left < right && nums[left] == nums[++left]) /*do nothing*/;
          //while (left < right && nums[right] == nums[--right]) /*do nothing*/;
          while (left < right && nums[left] == res.back()[1]) ++left;
          while (left < right && nums[right] == res.back()[2]) --right;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> res = sol.threeSum(nums);
  for (auto triple : res) {
    cout << "[ ";
    for (auto it : triple) cout << it << " ";
    cout << "]" << endl;
  }
  return 0;
}
