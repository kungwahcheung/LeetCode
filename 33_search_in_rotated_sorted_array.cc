#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    int middle;
    while (left <= right) {
      middle = left + (right-left)/2;
      if (target == nums[middle]) {
        return middle;
      } else if (nums[left] <= nums[middle]) {  // left half is sorted
        if (nums[left] <= target && target < nums[middle])
          right = middle - 1;
        else
          left = middle + 1;
      } else {                                  // right half is sorted
        if (nums[middle] < target && target <= nums[right])
          left = middle + 1;
        else
          right = middle - 1;
      }
    }
    return -1;
  }
};


int main() {
  Solution sol = Solution();
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  cout << sol.search(nums, target) << endl;
  return 0;
}
