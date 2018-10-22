#include <iostream>
#include <string>
#include <vector>

#include <cassert>  // assert

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int size = 1;  // the first element in nums is automatically included
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[size-1]) {
        nums[size] = nums[i];
        ++size;
      }
    }
    return size;
  }
};


int main() {
  Solution sol = Solution();
  vector<int> nums{0,0,1,1,1,2,2,3,3,4};
  int size = sol.removeDuplicates(nums);
  assert(5 == size);
  return 0;
}
