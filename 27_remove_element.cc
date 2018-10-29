#include <vector>
#include "util.h"

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int size = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != val) nums[size++] = nums[i];
    }
    return size;
  }
};


int main() {
  Solution sol = Solution();
  vector<int> nums{0,1,2,2,3,0,4,2};
  int val = 2;
  print_vector(nums);
  sol.removeElement(nums, val);
  print_vector(nums);
  return 0;
}
