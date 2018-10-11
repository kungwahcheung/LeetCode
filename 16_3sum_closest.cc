#include <algorithm>  // sort
#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>  // abs

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) return -target;
    sort(nums.begin(), nums.end());
    int res = nums[0] + nums[1] + nums[2];
    int three_sum = res;
    int left = 0, right = 0;
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i] == nums[i-1]) continue;
      left = i + 1;
      right = nums.size() - 1;
      while (left < right) {
        three_sum = nums[i] + nums[left] + nums[right];
        res = abs(three_sum - target) < abs(res - target) ? three_sum : res;
        if (three_sum == target) return target;
        if (three_sum < target)
          ++left;
        else
          --right;
      }
    }
    return res;
  }
};


int main() {
  Solution sol = Solution();
  vector<int> nums{-1, 2, 1, -4};
  int target = 1;
  cout << sol.threeSumClosest(nums, target) << endl;
  return 0;
}
