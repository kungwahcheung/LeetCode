#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int left = 0, middle = 0, right = nums.size()-1;
    while (left <= right) {
      middle = left + (right-left)/2;
      if (target == nums[middle]) {
        return true;
      }
      if (nums[left] <= nums[middle]) {
        // special case, for example, 2222342 and 2342222
        if (nums[left] == nums[middle] && nums[middle] == nums[right]) {  // cannot judge which half is sorted, trim the array first
          while (left <= right && nums[left] == nums[middle])
            ++left;
          while (left <= right && nums[right] == nums[middle])
            --right;
        } else {  // left half is sorted
          if (nums[left] <= target && target < nums[middle]) {
            right = middle - 1;
          } else {
            left = middle + 1;
          }
        }
      } else {  // right half is sorted
        if (nums[middle] < target && target <= nums[right]) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }
    }
    return false;
  }

  // a much clean version
  bool search_improved(vector<int>& nums, int target) {
    int left = 0, middle = 0, right = nums.size() - 1;
    while (left <= right) {
      middle = left + (right - left) / 2;
      if (target == nums[middle]) return true;
      if (nums[left] == nums[middle] && nums[middle] == nums[right]) {
        ++left;
        --right;
      } else if (nums[left] <= nums[middle]) {
        if (nums[left] <= target && target <= nums[middle]) right = middle - 1;
        else left = middle + 1;
      } else {
        if (nums[middle] <= target && target <= nums[right]) left = middle + 1;
        else right = middle - 1;
      }
    }
    return false;
  }

};

int main() {
  Solution sol = Solution();
  vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
  nums = {1, 3};
  int target = 3;
  bool flag = sol.search_improved(nums, target);
  //cout << sol.search(nums, target) << endl;
  cout << flag << endl;
  return 0;
}
